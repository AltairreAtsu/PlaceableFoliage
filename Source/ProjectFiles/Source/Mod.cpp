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

	switch (CustomBlockID)
	{
	case 3000:
		ReplaceDirtWithGrass(At);
		SetBlock(At, EBlockType::Flower3);
		break;
	case 3001:
		ReplaceDirtWithGrass(At);
		SetBlock(At, EBlockType::GrassFoliage);
		break;
	case 3002:
		ReplaceDirtWithGrass(At);
		SetBlock(At, EBlockType::Flower4);
		break;
	case 3003:
		ReplaceDirtWithGrass(At);
		SetBlock(At, EBlockType::FlowerRainbow);
		break;
	case 3004:
		ReplaceDirtWithGrass(At);
		SetBlock(At, EBlockType::Flower1);
		break;
	case 3005:
		ReplaceDirtWithGrass(At);
		SetBlock(At, EBlockType::Flower2);
		break;
	default:
		break;
	}
}

void ReplaceDirtWithGrass(const ModAPI::CoordinateInBlocks& At)
{
	CoordinateInBlocks blockBelow = At - CoordinateInBlocks(0, 0, 1);
	
	if (GetBlock(blockBelow).Type == EBlockType::Dirt) 
		SetBlock(blockBelow, EBlockType::Grass);
}

#if 1
void Event_BlockDestroyed(CoordinateInBlocks At, UniqueID CustomBlockID, bool Moved)
{}

void Event_BlockHitByTool(CoordinateInBlocks At, UniqueID CustomBlockID, wString ToolName, CoordinateInCentimeters ExactHitLocation, bool ToolHeldByHandLeft)
{}

void Event_Tick()
{}

void Event_OnLoad()
{}

void Event_OnExit()
{}

void Event_AnyBlockPlaced(CoordinateInBlocks At, BlockInfo Type, bool Moved)
{}

void Event_AnyBlockDestroyed(CoordinateInBlocks At, BlockInfo Type, bool Moved)
{}

void Event_AnyBlockHitByTool(CoordinateInBlocks At, BlockInfo Type, wString ToolName, CoordinateInCentimeters ExactHitLocation, bool ToolHeldByHandLeft)
{}
#endif

