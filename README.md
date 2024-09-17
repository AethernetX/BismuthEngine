# Bismuth engine

## Announcement

Development on Bismuth will be put on hold. I think my goal of making a game engine as an individual is too much for me and I would love to go back to it at some point when I think I am ready. The main issue was that I was struggling with vulkan and havng minimal experience in game engine dev forced me to learn little and only follow a tutorial step by step.

## What is Bismuth engine?
Bismuth is a game engine designed solely on being primarily used for making my games, but soon will be repurposed to make creating games accessible for users with no programming experience.

## Getting started
**YOU WILL NEED PREMAKE IN ORDER TO BUILD THE SANDBOX AND ENGINE, CMAKELISTS WILL BE MADE SOON**

You will also need the vulkan SDK installed.

Note: Unfortunately it is unknown whether the engine can run on Linux and MacOS. Testing and modification of the codebase will be required.

### Mingw Makefiles

clone the repo and in the directory with the `premake5.lua` and open command prompt or powershell.

enter the following:
```
premake gmake2
```

this will generate makefiles for the project. Then type the following

```
Mingw32-make
```
this should generate 2 folders call bin and bin-int, open bin > (configuration) > sandbox and you can run the sandbox application.

For additional help, you can also type `mingw32-make help` for more information on configurations.

## Visual Studio 2022

clone the repo and in the directory with the `premake5.lua` and open command prompt or powershell.

enter the following:
```
premake vs2022
```

When opening the solution, set the sandbox project as the starter projectand build the solution. Then hit f5 to run the sandbox.

## what kind of features will the Bismuth engine have?
[TBD]
- C# scripting and visual scripting
- Support on Windows, Linux, MacOS and HTML.
- Will use an ECS
- Will attempt to make events easy to work with and performant
- Use Jolt
- Use the .NET runtime
- Will attempt to make errors easy to debug.
- Will have object pooling built in
- Shortcuts (ideally inspired by blender)
- Use Vulkan and later on WebGL and Metal
- Game will run on the editor
- Editor will aim to be lightweight as possible
- open sourced
- collision layers
- No additional useless DLLs for exports
- Hot reloading
- Documentation
- A website to install
