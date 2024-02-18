中文 | English

![Static Badge](https://img.shields.io/badge/Qt-6.7.0-green?style=plastic&logo=qt)
![Static Badge](https://img.shields.io/badge/CMake-3.28-yellow?style=plastic&logo=cmake)
![Static Badge](https://img.shields.io/badge/License-GPL%202.0-blue?style=plastic)
![Static Badge](https://img.shields.io/badge/Made%20with-Love-red?style=plastic)

<details>
  <summary>目录</summary>
  <ol>
    <li>
      <a href="#关于项目">关于项目</a>
      <ul>
        <li><a href="#用到的库">用到的库</a></li>
      </ul>
    </li>
    <li>
      <a href="#编译">编译</a>
      <ul>
        <li><a href="#先决条件">先决条件</a></li>
        <li><a href="#安装">安装</a></li>
        <li><a href="#降级至Qt5">降级至Qt5</a></li>
      </ul>
    </li>
    <li><a href="#使用指南">使用指南</a></li>
    <li><a href="#待办">待办</a></li>
    <li><a href="#贡献">贡献</a></li>
    <li><a href="#许可证">许可证</a></li>
    <li><a href="#致谢">致谢</a></li>
  </ol>
</details>

# 关于项目
![](./docs/img/screenshot.png)
使用Qt编写的简易时钟，目前可以以12小时制显示时间、日期、星期。

# 用到的库
本项目用到了以下的库：

- ![Static Badge](https://img.shields.io/badge/Qt-6.7.0-green?style=flat-square&logo=qt)

## 编译

**请注意**：本项目使用的Qt与CMake版本较新

### 先决条件

在开始编译前，请确保您安装了`Qt`与`CMake`。我们推荐的Qt版本为5.15.15+，如需使用Qt5编译请参考“降级到Qt5”.

然后，请您修改`CMakeLists.txt`中的CMake前缀为您的Qt路径，例：

  ```cmake
  set(CMAKE_PREFIX_PATH "D:/IDE/Qt/6.7.0/msvc2019_64")
  ```

### 安装

1. 克隆仓库至本地，`cd`至项目根目录（含`CMakeLists.tst`），然后创建`Build`目录。

   ```sh
   mkdir build
   cd build
   ```
2. 构建项目
   ```sh
   cmake ..
   ```

### 降级至Qt5

要使用Qt5构建本项目，只需在将CMake前缀改为您Qt5的路径，再将`find_package(Qt6 COMPONENTS`更改为`find_package(Qt5 COMPONENTS`。

```cmake
cmake_minimum_required(VERSION 3.28)
project(Clock)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH <path_to_qt>)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
```

## 使用指南

目前只是能看时间，指南将在稍后更新世界时钟/首选项窗口时更新。

### 待办
- [x] 能看时间
- [ ] 世界时钟
- [ ] 调整时间
- [ ] 无边框窗口&全屏模式
- [ ] 闹钟（待定）
- [ ] 多语言支持
   - [ ] 中文
   - [ ] 英语

### 贡献
- 如果您有建议或者找到了bug，请提交issue。
- 如果您想要优化代码/新增功能到此项目，请提交拉取请求。

### 许可证

本项目的许可证为GNU Public License 2.0，可以参考项目根目录中的`LICENSE`。

### 致谢

- 框架
  - Qt
- 工具
  - CMake
- 字体
  - Ubuntu