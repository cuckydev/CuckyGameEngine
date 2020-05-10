/*
Project: CuckyGameEngine

File: CGE/Render.cpp
Purpose: Define the render subsystem namespace

Authors: Regan Green (cuckydev)
*/

//Declaration
#include "Render.h"

//Clear color command
CGE::Render::DLCommand_ClearColor::DLCommand_ClearColor(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
CGE::Render::DLCommand_ClearColor::~DLCommand_ClearColor() {}
void CGE::Render::DLCommand_ClearColor::Execute(CGE::Render::Interface_Base *render) const { render->ClearColor(r, g, b); }

//Clear depth command
CGE::Render::DLCommand_ClearDepth::DLCommand_ClearDepth()  {}
CGE::Render::DLCommand_ClearDepth::~DLCommand_ClearDepth() {}
void CGE::Render::DLCommand_ClearDepth::Execute(CGE::Render::Interface_Base *render) const { render->ClearDepth(); }
