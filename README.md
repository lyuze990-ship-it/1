# 5v5 Tactical Shooting Game

一个基于C++的仿CS:GO风格5v5战术射击游戏

## 🎮 游戏特性

- **5v5团队对战**: 红蓝两支队伍对战
- **血量机制**: 玩家血量(100HP)、护甲、救治包系统
- **经济系统**: 击杀获得金钱，购买武器装备
- **地图**: CS:GO沙漠地图(Dust2)
- **武器系统**: 手枪、冲锋枪、步枪、狙击枪、刀具等多种武器
- **射击反馈**: 后座力系统、准确度衰减、枪口闪光、弹孔标记
- **胜利机制**: 消灭全部敌人、完成目标、时间结束
- **高清人物建模**: 清晰的角色模型和动画

## 📁 项目结构

```
ShootingGame/
├── src/
│   ├── core/              # 引擎核心
│   │   ├── engine.h/cpp   # 主引擎
│   │   └── window.h/cpp   # 窗口管理
│   ├── game/              # 游戏逻辑
│   │   ├── game_manager.h/cpp
│   │   ├── player.h/cpp
│   │   ├── team.h/cpp
│   │   ├── weapon.h/cpp
│   │   └── map.h/cpp
│   ├── graphics/          # 图形渲染
│   │   ├── renderer.h/cpp
│   │   ├── shader.h/cpp
│   │   ├── model.h/cpp
│   │   └── camera.h/cpp
│   ├── physics/           # 物理系统
│   │   ├── physics_engine.h/cpp
│   │   └── collision.h/cpp
│   └── main.cpp
├── assets/                # 游戏资源
├── CMakeLists.txt
└── README.md
```

## 🚀 快速开始

### 系统需求
- C++17 或更高版本
- CMake 3.16+
- OpenGL 4.5+

### 依赖安装

#### Ubuntu/Debian
```bash
sudo apt-get install libglfw3-dev libglm-dev libassimp-dev libbullet-dev
```

#### macOS
```bash
brew install glfw3 glm assimp bullet3
```

#### Windows (VCPKG)
```bash
vcpkg install glfw3:x64-windows glm:x64-windows assimp:x64-windows
```

### 编译和运行

```bash
# 创建构建目录
mkdir build && cd build

# 生成构建文件
cmake ..

# 编译
make

# 运行游戏
./ShootingGame
```

## 🎯 核心系统

### 5v5团队系统
- 红队(恐怖分子) vs 蓝队(反恐精英)
- 各5名玩家，共10人
- 独立的生成点和武器购买系统
- 队伍得分追踪

### 血量和护甲机制
- 基础血量: **100 HP**
- 护甲等级: **0-200**
- 护甲吸收伤害的 **50%**
- 救治包恢复 **25 HP**
- 伤害反馈显示

### 经济系统
- 初始金钱: 2400
- 击杀敌人: +300金钱
- 死亡惩罚: -200金钱
- 完成目标: +300金钱
- 购买武器系统

### 武器系统

| 武器 | 伤害 | 火速 | 准确度 | 装弹 | 价格 |
|------|------|------|--------|------|------|
| USP-S | 40 | 10/s | 85% | 12 | 500 |
| P250 | 35 | 10/s | 75% | 13 | 1200 |
| MP9 | 26 | 16/s | 70% | 30 | 1500 |
| AK-47 | 36 | 12/s | 75% | 30 | 2500 |
| M4A4 | 21 | 13/s | 80% | 30 | 3100 |
| AWP | 115 | 4/s | 95% | 10 | 4750 |
| 刀具 | 65 | - | 100% | ∞ | 0 |

### 地图系统
- **Dust2沙漠地图**: 以CS:GO经典地图为基础
- **红队生成点**: (-10, 1, -10)附近
- **蓝队生成点**: (10, 1, 10)附近
- **轰炸目标A**: (-15, 1, 15)
- **轰炸目标B**: (15, 1, -15)
- **多个战斗区域**、掩体和制高点

### 射击反馈系统

#### 后座力系统
- 每次射击增加准确度偏差
- 武器特定的后座力参数
- 射击间隔重置后座力

#### 准确度衰减
- 静止射击: 基础准确度
- 移动时: 准确度降低30%
- 蹲下时: 准确度提升20%

#### 视觉反馈
- 枪口闪光动画
- 弹孔标记显示
- 伤害指示器
- 血迹效果

### 胜利条件

1. **团队消灭**: 消灭所有敌方玩家
2. **目标完成**: 
   - 恐怖分子: 成功安装炸弹
   - 反恐精英: 防止炸弹爆炸
3. **时间结束**: 120秒无人消灭，恐怖分子获胜
4. **首达8分**: 率先赢得8轮的队伍获胜

## 🎮 操作控制

| 操作 | 按键 |
|------|------|
| 前进 | W |
| 后退 | S |
| 左移 | A |
| 右移 | D |
| 射击 | 鼠标左键 |
| 换弹 | R |
| 跳跃 | 空格 |
| 蹲下 | Ctrl |
| 换武器 | 数字键 1-5 |
| 视角 | 鼠标移动 |
| 语音 | V |
| 小地图 | M |

## 🔧 技术栈

| 组件 | 技术 |
|------|------|
| 编程语言 | C++17 |
| 图形API | OpenGL 4.5 |
| 窗口系统 | GLFW 3.3 |
| 数学库 | GLM |
| 模型加载 | ASSIMP |
| 物理引擎 | Bullet Physics |
| 音频系统 | OpenAL |
| 构建系统 | CMake |

## 📋 开发计划

### Phase 1 (完成) ✅
- [x] 项目结构搭建
- [x] 引擎核心框架
- [x] 窗口和事件系统
- [x] OpenGL渲染基础
- [x] 游戏逻辑框架
- [x] 玩家和队伍系统
- [x] 武器系统
- [x] 地图结构

### Phase 2 (进行中) 🔄
- [ ] 高清人物建模集成
- [ ] Dust2地图完整渲染
- [ ] 碰撞检测系统完善
- [ ] 物理引擎集成
- [ ] 输入系统完整化

### Phase 3 (规划) 📋
- [ ] 射击反馈视觉效果
- [ ] 血迹和伤害显示
- [ ] 爆炸效果
- [ ] 粒子系统
- [ ] 光影系统

### Phase 4 (规划) 📋
- [ ] HUD界面设计
- [ ] 计分板显示
- [ ] 小地图实现
- [ ] 枪声系统
- [ ] 背景音乐

### Phase 5 (规划) 📋
- [ ] 网络多人支持
- [ ] 服务器架构
- [ ] 性能优化
- [ ] 反作弊系统

## 📚 代码文档

### 核心类

#### Engine (引擎)
```cpp
class Engine {
    void Initialize(title, width, height);
    void Run();
    void Shutdown();
};
```

#### Player (玩家)
```cpp
class Player {
    void TakeDamage(damage);
    void Fire();
    void Reload();
    void Move(direction, speed);
    void Jump();
};
```

#### Team (队伍)
```cpp
class Team {
    void AddPlayer(player);
    int GetAlivePlayerCount();
    void SpawnAllPlayers(spawnPoint);
};
```

#### Weapon (武器)
```cpp
class Weapon {
    void Fire();
    void Reload();
    bool CanFire();
    int GetDamage();
    float GetRecoil();
};
```

## 🐛 调试和日志

### 编译调试版本
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

### 启用详细日志
```cpp
#define DEBUG_LOG 1
```

## 📝 注意事项

- 确保GPU驱动支持OpenGL 4.5+
- 建议在1920x1080或更高分辨率下运行
- 首次运行可能需要加载资源

## 🤝 贡献指南

欢迎提交 Pull Request 和 Issue！

## 📄 许可证

MIT License

---

**开发中** 🚀 | 最后更新: 2026年6月
