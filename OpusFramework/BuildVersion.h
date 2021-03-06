#pragma once

enum class EngineVersion
{
	NotSet,
	HaloReach
};

enum class BuildVersion
{
	NotSet,
	Build_1_887_0_0,
	Build_1_1035_0_0,
	Build_1_1186_0_0,
	Build_1_1211_0_0,
	Build_1_1246_0_0,
	Build_1_1270_0_0,
	Count
};

constexpr intptr_t GetBuildBaseAddress(BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0:
	case BuildVersion::Build_1_1035_0_0:
	case BuildVersion::Build_1_1186_0_0:
	case BuildVersion::Build_1_1211_0_0:
	case BuildVersion::Build_1_1246_0_0:
	case BuildVersion::Build_1_1270_0_0:
		return 0x180000000;
	}
	return ~intptr_t();
}

constexpr intptr_t GetEngineTopAddress(BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0:
		return 0x184925000;
	case BuildVersion::Build_1_1035_0_0:
		return 0x18450D000;
	case BuildVersion::Build_1_1186_0_0:
		return 0x183985000;
	case BuildVersion::Build_1_1211_0_0:
		return 0x183986000;
	case BuildVersion::Build_1_1246_0_0:
		return 0x18397F000;
	case BuildVersion::Build_1_1270_0_0:
		return 0x18397F000;
	}
	return ~intptr_t();
}

constexpr const char* GetEngineFilename(EngineVersion engineVersion)
{
	switch (engineVersion)
	{
	case EngineVersion::HaloReach:
		return "haloreach.dll";
	}
	FATAL_ERROR("Unsupported GameVersion");
}

extern bool IsEngineLoaded(EngineVersion engineVersion);
extern void* GetEngineMemoryAddress(EngineVersion engineVersion);
