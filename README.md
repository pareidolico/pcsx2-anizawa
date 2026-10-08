# PCSX2 for Windows 8.1 (unofficial fork)

![Windows Build Status](https://img.shields.io/github/actions/workflow/status/pareidolico/pcsx2-anizawa/windows_build_matrix.yml?branch=claude%2Fpeaceful-allen-j67c6l&label=%F0%9F%96%A5%EF%B8%8F%20Windows%20Builds)

A personal fork of [PCSX2](https://github.com/PCSX2/pcsx2), the free and open-source PlayStation 2 emulator, changed so that it runs on **Windows 8.1 (64-bit)**. Upstream PCSX2 requires Windows 10 or newer.

This fork is not affiliated with or supported by the PCSX2 team. Please don't report problems with these builds to the PCSX2 project.

## Download

Get the latest build from the [Releases page](https://github.com/pareidolico/pcsx2-anizawa/releases):

| File | Use it if |
| --- | --- |
| `PCSX2-win81-x64-avx2.zip` | Your CPU supports AVX2 (Intel Haswell / AMD Excavator and newer). Faster. |
| `PCSX2-win81-x64-sse4.zip` | Your CPU is older, or you're not sure. |

### Requirements

- Windows 8.1 64-bit with all updates installed (Windows 10 and 11 also work).
- [Visual C++ 2015–2022 x64 redistributable](https://aka.ms/vs/17/release/vc_redist.x64.exe).
- A GPU that supports Direct3D 11 (Direct3D 10-class or newer).
- A BIOS dump from a PS2 console you own. See the [PCSX2 BIOS guide](https://pcsx2.net/docs/setup/bios/).

Unzip anywhere and run `pcsx2-qt.exe`.

## Differences from upstream PCSX2

On Windows 8.1:

- **Direct3D 12 is unavailable.** The automatic renderer picks Direct3D 11; OpenGL and Vulkan also work if your driver supports them.
- **Fastmem is disabled.** It needs memory APIs that only exist on Windows 10 1803+, so games are somewhat more CPU-heavy than upstream. On Windows 10/11 these builds behave like upstream.
- **Tearing mode with VSync off (DXGI "allow tearing") is unavailable**, as it needs DXGI 1.5.

Under the hood:

- Windows 10-only memory functions (`VirtualAlloc2`, `MapViewOfFile3`, `UnmapViewOfFile2`) are loaded at runtime, with a fallback that works on 8.1.
- `d3d12.dll`, `dxcompiler.dll` and `WinPixEventRuntime.dll` are delay-loaded, so the program starts without them.
- The Direct3D 11 renderer only requires DXGI 1.2.
- The UI uses **Qt 6.8.4** patched with [qt6windows7](https://github.com/crystalidea/qt6windows7) instead of stock Qt 6.12, which needs Windows 10.
- Builds use the **Visual Studio 2022** toolset, since the VS 2026 runtime only supports Windows 10 and later.

## Building

Builds are produced by GitHub Actions (`.github/workflows/windows_build_matrix.yml`). The dependency script `.github/workflows/scripts/windows/build-dependencies.bat` fetches Qt 6.8.4 and the qt6windows7 patches pinned by commit and builds everything else.

To build locally, follow the [upstream build guide](https://pcsx2.net/docs/advanced/building/), using Visual Studio 2022 and the dependency script from this repository.

## Performance tips for low-end PCs

- Use the AVX2 build if your CPU supports it.
- Graphics: Direct3D 11, native resolution, Blending Accuracy *Minimum*, no extra filtering.
- Emulation: try *EE Cycle Rate* -1 or -2 and *Instant VU1*. Change these per game (right-click a game → Properties) so other games aren't affected.

## License

PCSX2 is licensed under the [GNU GPL v3](COPYING.GPLv3), and so is this fork. All credit for the emulator goes to the [PCSX2 team and contributors](https://github.com/PCSX2/pcsx2/graphs/contributors).
