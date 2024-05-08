# Unreal Plug-in Example

## Prerequisites

1. Unreal Engine 5.3.2 or 5.4.0
1. Visual Studio 2022
   a. Desktop development with C++
   a. Game development with C++

## Quick-start

1. Clone this repository into the folder where you store your Unreal projects.  By default, this is the `Unreal Projects` folder in
   the `Documents` folder.
1. Create the `ThirdParty` folder in the `Source` folder in the repository folder.
1. Create the `LiveAwareLabs` folder in the `ThirdParty` folder you created.
1. Copy the contents of the Zip file given to you
   into the `LiveAwareLabs` folder you created.  Ensure the relative path of the `RecorderPlugin.h` file is
   `Source\ThirdParty\LiveAwareLabs\RecorderPlugin.h`, similarly for the rest of the files.
1. Right-click the `UnrealPluginExample.uproject` file and select `Generate Visual Studio project files`.  On Windows 11, you will
   need to first select `Show more options`.
1. Double-click the `UnrealPluginExample.sln` file.  Visual Studio will open.
1. Press `F5`.  This will build the project and run the Unreal editor.

Press the `⏵` button to exercise the plug-in.  If the Live Aware Desktop Recorder is not running, it will start.

## Installation

1. Perform steps 2, 3, and 4 above for your Unreal project.
1. Add the following lines to your `.Build.cs` file.
   ```
		PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "..", "ThirdParty", "LiveAwareLabs", "recorder-unreal-plugin.lib"));
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "..", "ThirdParty", "LiveAwareLabs"));
   ```
1. Include the plug-in's header file with `#include <RecorderPlugin.h>` in your code that will use the plug-in.

If Visual Studio complains it cannot find that header file, add `$(ProjectDir)Source\ThirdParty\LiveAwareLabs` to the
`Include Directories` field of the `VC++ Directories` section of the `Properties` dialog of the `UnrealPluginExample` project in
the `Games` solution folder.  Note that since Unreal created these project files, you will need to perform this step again if you
regenerate the Visual Studio project files as described in step 4.  Your project will build without this change since the Unreal
build system relies on your `.Build.cs` file.
