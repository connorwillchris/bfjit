const std = @import("std");

pub fn build(b: *std.Build) void {
    const exe = b.addExecutable(.{
        .name = "bfjit",
        .target = b.resolveTargetQuery(.{
            //.os_tag = if (windows) .windows else if (linux) .linux else null,
            .os_tag = .windows,
        }),
    });

    exe.linkLibC();
    exe.addCSourceFiles(.{
        .files = &.{
            "src/bf.c",
            "src/main.c",
        },
    });
    b.installArtifact(exe);
}
