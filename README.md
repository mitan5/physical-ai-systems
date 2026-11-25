# physical-ai-systems

End-to-end Physical AI and robotics systems implementations spanning deterministic C++20 data pipelines, ROS 2 middleware, physics simulation, policy learning, and multimodal telemetry infrastructure.

## Modules

| Directory | Domain | Core Focus | Status |
| :--- | :--- | :--- | :--- |
| `01-cpp-ring-buffer/` | Real-Time Systems | Lock-free SPSC ring buffer, zero-allocation sensor ingestion (`ASan`/`TSan` verified) | Planned |
| `02-ros2-sensor-ws/` | Robotics Middleware | ROS 2 lifecycle nodes, `tf2` transforms, and MoveIt 2 motion planning | Planned |
| `04-mujoco-ekf/` | State Estimation | MJCF manipulation scene and C++ Extended Kalman Filter | Planned |
| `05-isaac-sim2sim/` | Simulation & RL | GPU-parallel policy training in Isaac Lab with zero-shot MuJoCo transfer | Planned |
| `07-lerobot-vla/` | Imitation & VLAs | Action-chunking / diffusion policy fine-tuning and real-time camera inference | Planned |
| `09-mcap-lakehouse-trt/` | Data Infra & Edge | MCAP-to-Parquet multimodal lakehouse pipeline and C++ TensorRT inference server | Planned |

## Toolchain
* **OS & Compilers:** Ubuntu 24.04 LTS (`x86_64`), GCC 14, Clang 18, CMake 3.28+, Ninja
* **Verification:** AddressSanitizer (`ASan`), UndefinedBehaviorSanitizer (`UBSan`), ThreadSanitizer (`TSan`)
