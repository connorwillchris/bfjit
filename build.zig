const std = @import("std");

pub fn build(b: *std.Build) void {
    const exe = b.addExecutable(.{
        .name = "bfjit",
        .root_module = b.addModule("bfjit", .{
            .link_libc = true,
            .target = b.resolveTargetQuery(.{ .os_tag = .windows }),
        }),
    });

    exe.linkLibC();
    exe.addIncludePath(b.path("src/"));

    exe.addCSourceFiles(.{
        .files = &.{
            "src/bf.c",
            "src/main.c",

            // hardcode it as windows for now...
            "src/platforms/windows.c",
        },
    });
    b.installArtifact(exe);
}
