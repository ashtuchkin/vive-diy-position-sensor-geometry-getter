# vive-diy-position-sensor-geometry-getter
Small console program to generate base station geometry for [vive-diy-position-sensor project](https://github.com/ashtuchkin/vive-diy-position-sensor).

## How to use
 1. Download both `openvr_api.dll` and `vive-diy-position-sensor-geometry-getter.exe` from [release page](https://github.com/ashtuchkin/vive-diy-position-sensor-geometry-getter/releases/tag/1.0).
 1. Make sure SteamVR is setup and running on your computer, with Room Setup done successfully. 
 1. Run `vive-diy-position-sensor-geometry-getter.exe`. It should print two lines like shown below (with your data of course). Save these lines and use them to configure your Teensy.
 
```
b0 origin -1.528176 2.433746 -1.969393 matrix -0.839498 0.340747 -0.423244 -0.041220 0.736752 0.674906 0.541798 0.584028 -0.604456
b1 origin 1.732790 2.514255 0.709026 matrix 0.454144 -0.645781 0.613776 0.026748 0.698489 0.715120 -0.890527 -0.308350 0.334488
```
 
## Compilation from source
Just open in Visual Studio and build. Be sure to have [openvr](https://github.com/ValveSoftware/openvr) project cloned side-by-side with this one.
