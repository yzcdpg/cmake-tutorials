# cmake tutorials


## Config.h.in
在`CMake`项目中，`config.h.in`（或类似命名的`.h.in`文件）是一个头文件模板，用于通过`CMake`的 `configure_file`命令生成最终的头文件（通常是`config.h`）。其中定义的变量（通常是`C/C++`预处理器宏）在代码中起到传递配置信息的作用。

`config.h.in`文件（以及生成的`config.h`文件）中的变量是单向的，即只能将`CMake`中的配置信息传递到`C/C++`代码中，无法直接从`C/C++`代码中读取值到`CMake`或`config.h.in`。

* `config.h.in`是一个模板文件，`CMake`通过`configure_file`命令将其处理为`config.h`，将`CMake`变量的值（如 `@VARIABLE@`）替换为实际值。
* 生成的`config.h`是静态的头文件，包含固定的宏定义，供`C/C++`代码在编译时使用。
* 这个过程是单向的：`CMake` → `config.h.in` → `config.h` → 编译器。

## add_subdirectory
用于添加子目录到项目构建系统的重要命令。它的主要作用是将子目录中的`CMakeLists.txt`文件纳入当前项目的构建过程，从而实现模块化构建和组织复杂项目。

* 模块化项目组织：将项目分解为多个子目录，每个子目录包含独立的`CMakeLists.txt`文件，用于定义该子目录的构建规则（如目标、库、源文件等）。
* 管理子模块或子项目：支持嵌套的`CMake`项目结构，允许在主项目中包含子项目或外部模块（如第三方库）。
* 隔离配置：每个子目录可以有自己的配置（如源文件、编译选项、依赖库），提高代码的可维护性和可重用性。
* 支持递归构建：`CMake`会递归处理子目录中的`CMakeLists.txt`，将子目录的目标（如可执行文件或库）集成到主项目的构建系统中。
```
add_subdirectory(<source_dir> [<binary_dir>] [EXCLUDE_FROM_ALL])
```
* `<source_dir>`：子目录的路径，包含子目录的`CMakeLists.txt`文件。通常是相对于当前`CMakeLists.txt`的路径。
* `<binary_dir>`（可选）：子目录的构建输出目录，指定生成文件（如对象文件、可执行文件）的存放位置。如果未指定，`CMake`使用主项目的构建目录结构。
* `EXCLUDE_FROM_ALL`（可选）：表示子目录中的目标不会自动包含在父项目的默认构建目标中，只有显式指定时才会构建。

## target_compile_definitions
用于为特定目标（`target`，如可执行文件或库）添加编译定义（`preprocessor definitions`）的命令。它的主要作用是在编译目标时设置`C/C++`预处理器宏（`preprocessor macros`），从而影响源代码的条件编译或行为。

```
target_compile_definitions(<target> [PUBLIC|PRIVATE|INTERFACE] <definitions>...)
```

* `<target>`：目标名称，例如通过`add_executable`或`add_library`定义的可执行文件或库。
* 访问修饰符：
  * `PUBLIC`：宏定义对目标本身及其依赖的目标都可见。
  * `PRIVATE`：宏定义仅对目标本身可见，不影响依赖它的目标。
  * `INTERFACE`：宏定义仅对依赖该目标的其他目标可见，目标本身不可见。
* `<definitions>`：要添加的宏定义，格式为：
  * 简单宏：`MY_MACRO`（等价于`#define MY_MACRO`）。
  * 带值的宏：`MY_MACRO=1`（等价于`#define MY_MACRO 1`）。



## option
用于定义一个用户可配置的选项（`option`），允许在配置项目时通过命令行、`CMake GUI`或缓存文件启用或禁用某些功能。它的主要作用是为项目提供可定制的开关，控制构建行为、特性或配置，而无需修改`CMakeLists.txt`文件。

```
option(<variable> "<help_text>" [value])
```
* `<variable>`：选项的名称，存储选项值的`CMake`变量（如`ENABLE_DEBUG`）。
* `<help_text>`：选项的描述，显示在`CMake GUI`或`cmake -LA`的输出中，帮助用户理解选项的作用。
* [value]：选项的默认值，通常为`ON`或`OFF`（布尔值）。如果未指定，默认值为`OFF`。


