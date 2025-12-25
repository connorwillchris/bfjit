const std = @import("std");

pub fn build(b: *std.Build) void {
    const exe = b.addExecutable(.{
        .name = "bfjit",
        .target = b.standardTargetOptions(.{ .default_target = .{ .os_tag = .windows } }),
    });

    exe.linkLibC();
    exe.addCSourceFiles(.{
        .files = &.{
            "src/bf.c",
            "src/main.c",
        }, //.flags = &.{"-std=c89"} });
    });
    b.installArtifact(exe);
}
