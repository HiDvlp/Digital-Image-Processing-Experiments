# 数字图像处理-第1次实验代码使用说明

## 环境要求
| 工具 | 版本 |
|------|------|
| Ubuntu | 24.04 LTS (WSL2) |
| GCC / G++ | 13.2.0 |
| CMake | 3.28.3 |
| GNU Make | 4.3 |
| OpenCV | 4.6.0 |

## 安装依赖
```bash
sudo apt update
sudo apt install build-essential cmake libopencv-dev -y
```

## 项目结构
```
Digital-ImagE-Processing/Experiments/chap_1
├── 1-1.jpg
├── 1-2.jpg
├── 1-2.tif
├── README.md
├── exp1.png
├── task_1                                          
│   ├── subtask_1                   # 全局直方图均衡化                        
│   │   ├── 1-2.jpg                             
│   │   ├── CMakeLists.txt  
│   │   ├── equalizeHist.cpp        # 定义实现函数
│   │   ├── equalizeHist.hpp        # 声明实现函数
│   │   ├── s-r.jpg
│   │   └── subtask_1.cpp           # 主程序
│   └── subtask_2                   # 局部直方图均衡化
│       ├── 1-2.jpg
│       ├── CMakeLists.txt
│       ├── equalizeHistLocal.cpp   # 定义实现函数
│       ├── equalizeHistLocal.hpp   # 声明实现函数
│       └── subtask_2.cpp           # 主程序
└── task_2                          # 基于全局及局部统计量的局部增强算法
    ├── 1-1.jpg                     
    ├── CMakeLists.txt
    ├── localHistEnhance.cpp        # 定义实现函数
    ├── localHistEnhance.hpp        # 声明实现函数
    └── task_2.cpp                  # 主程序
```

## 使用说明
### 克隆仓库
```bash
git clone https://github.com/HiDvlp/Digital-Image-Processing-Experiments/tree/main/Experiments/chap_1
```
### 编译和运行
以第1个任务的第1个子任务（全局直方图均衡化）为例，
```bash
cd Experiments/chap_1/task_1/subtask_1
mkdir -p build && cd build
cmake ..
make
cd .. && ./build/subtask_1
```
运行后将在当前目录生成处理后的图像文件`Processed Image.jpg`

## 实验说明

### 第 1 章：图像增强

| 实验 | 内容 | 关键实现函数 |
|------|------|----------|
| task_1/subtask_1 | 全局直方图均衡化 | equalizeHist() |
| task_1/subtask_2 | 局部直方图均衡化 | equalizeHistLocal() |
| task_2 | 基于全局和局部统计量的局部直方图增强 | localHistEnhance() |

#### 参数说明（以 task_2 为例）

| 参数 | 说明 | 推荐值 |
|------|------|--------|
| `k0`, `k1` | 均值约束区间 | 0.0 ~ 0.5 |
| `k2`, `k3` | 方差约束区间 | 0.0 ~ 0.3 |
| `C` | 增强系数 | 10.0 ~ 30.0 |
| `winSize` | 局部窗口大小 | 3 |


## 作者

- **HiDvlp**
- Email: gaofz666@gmail.com

## 许可证

本仓库仅用于课程学习交流，代码未经许可不得用于商业用途。