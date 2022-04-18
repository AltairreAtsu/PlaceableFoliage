#include "GameAPI.h"
#include "Mod.h"

/************************************************************
	Config Variables (Set these to whatever you need. They are automatically read by the game.)
*************************************************************/

UniqueID ThisModUniqueIDs[] = { 3000, 3001, 3002, 3003, 3004, 3005 }; // All the UniqueIDs this mod manages. Functions like Event_BlockPlaced are only called for blocks of IDs mentioned here. 

float TickRate = 1;							 // Set how many times per second Event_Tick() is called. 0 means the Event_Tick() function is never called.

/************************************************************* 
//	Functions (Run automatically by the game, you can put any code you want into them)
*************************************************************/


// Run every time a block is placed
void Event_BlockPlaced(CoordinateInBlocks At, UniqueID CustomBlockID, bool Moved)
{
	CoordinateInBlocks blockBelow = At - CoordinateInBlocks(0, 1, 0);
	switch (CustomBlockID)
	{
	case 3000:
		ReplaceDirtWithGrass(blockBelow);
		SetBlock(At, EBlockType::Flower3);
		break;
	case 3001:
		ReplaceDirtWithGrass(blockBelow);
		SetBlock(At, EBlockType::GrassFoliage);
		break;
	case 3002:
		ReplaceDirtWithGrass(blockBelow);
		SetBlock(At, EBlockType::Flower4);
		break;
	case 3003:
		ReplaceDirtWithGrass(blockBelow);
		SetBlock(At, EBlockType::FlowerRainbow);
		break;
	case 3004:
		ReplaceDirtWithGrass(blockBelow);
		SetBlock(At, EBlockType::Flower1);
		break;
	case 3005:
		ReplaceDirtWithGrass(blockBelow);
		SetBlock(At, EBlockType::Flower2);
		break;
	default:
		break;
	}
}

void ReplaceDirtWithGrass(const ModAPI::CoordinateInBlocks& blockBelow)
{
	if (GetBlock(blockBelow).Type == EBlockType::Dirt) SetBlock(blockBelow, EBlockType::Grass);
}

// Run every time a block is destroyed
void Event_BlockDestroyed(CoordinateInBlocks At, UniqueID CustomBlockID, bool Moved)
{}


// Run every time a block is hit by a tool
void Event_BlockHitByTool(CoordinateInBlocks At, UniqueID CustomBlockID, std::wstring ToolName)
{
	if (ToolName == L"T_Stick") {

	}
	else if (ToolName == L"T_Pickaxe_Stone") {

	}
	else if (ToolName == L"T_Arrow") {

	}
	else {

	}
}


// Run X times per second, as specified in the TickRate variable at the top
void Event_Tick()
{}



// Run once when the world is loaded
void Event_OnLoad()
{}

// Run once when the world is exited
void Event_OnExit()
{}

/*******************************************************

	For all the available game functions you can call, look at the GameAPI.h file

*******************************************************/
