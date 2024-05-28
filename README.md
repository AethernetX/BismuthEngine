# Bismuth engine

## What is Bismuth engine?
Bismuth is a game engine designed solely on being primarily used for making my games, but soon will be repurposed to make creating games accessible for users with no programming experience.

## Getting started
**YOU WILL NEED PREMAKE IN ORDER TO BUILD THE SANDBOX AND ENGINE, CMAKELISTS WILL BE MADE SOON**

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
- Support on Windows, Linux and MacOS
