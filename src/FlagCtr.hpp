#ifndef INK_SDLWRAPPER_HELPER_STRUCT_FLAG_CTR_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_HELPER_STRUCT_FLAG_CTR_HEADER_FILE_GUARD

namespace ink::SDL {
	
	// T-defined flag constructor.
	// Typically, a functional Flag Constructor Structure, wherein each function toggles flag of the same name on or off,
	// and returns a reference to the structure, allowing for chaining functions.
	template<typename T> struct FlagCtr;
	
}

#endif
