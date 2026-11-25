#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>

inline constexpr std::size_t kCacheLine  = 64;
inline constexpr std::size_t kLidarPoints = 224;

// 64 bytes = exactly one cache line.
struct alignas(kCacheLine) ImuPacket {
    std::uint64_t timestamp_ns;   //  0  sensor time, nanoseconds
    std::uint32_t seq;            //  8  monotonically increasing
    std::uint32_t flags;          // 12  status bits
    float accel[3];               // 16  m/s^2  (x, y, z)
    float gyro[3];                // 28  rad/s
    float mag[3];                 // 40  microtesla
    float temperature_c;          // 52
    std::uint8_t reserved[8];     // 56  pad to 64, keep zeroed
};

// 704 bytes = 11 cache lines. Header first, then arrays of points.
struct alignas(kCacheLine) LidarPacket {
    std::uint64_t timestamp_ns;       //  0
    std::uint32_t seq;                //  8
    std::uint16_t point_count;        // 12  valid entries, <= kLidarPoints
    std::uint16_t flags;              // 14
    float angle_min_rad;              // 16
    float angle_increment_rad;        // 20
    std::uint8_t reserved[8];         // 24  pad header to 32
    std::uint16_t range_mm[kLidarPoints];   // 32
    std::uint8_t  intensity[kLidarPoints];  // 480
};

// Compile-time checks: these fail the build if the layout drifts.
static_assert(std::is_trivially_copyable_v<ImuPacket>);
static_assert(std::is_standard_layout_v<ImuPacket>);
static_assert(sizeof(ImuPacket) == 64);
static_assert(alignof(ImuPacket) == kCacheLine);

static_assert(std::is_trivially_copyable_v<LidarPacket>);
static_assert(std::is_standard_layout_v<LidarPacket>);
static_assert(sizeof(LidarPacket) == 704);
static_assert(sizeof(LidarPacket) % kCacheLine == 0);
static_assert(offsetof(LidarPacket, range_mm) == 32);
static_assert(offsetof(LidarPacket, intensity) == 480);