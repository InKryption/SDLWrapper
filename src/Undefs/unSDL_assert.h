
#ifdef SDL_disabled_assert
static inline auto disabled_assert(bool condition)
{
	SDL_disabled_assert(condition);
	#undef SDL_disabled_assert
}
#endif

#ifdef SDL_assert_always
static inline auto assert_always(bool condition)
{
	SDL_assert_always(condition);
	#undef SDL_assert_always
}
#endif

#ifdef SDL_enabled_assert
static inline auto enabled_assert(bool condition)
{
	SDL_enabled_assert(condition);
	#undef SDL_enabled_assert
}
#endif

#undef SDL_NULL_WHILE_LOOP_CONDITION

#ifdef SDL_ASSERT_LEVEL
	static constexpr auto ASSERT_LEVEL = SDL_ASSERT_LEVEL;
	#undef SDL_ASSERT_LEVEL
#endif

#ifdef SDL_DEFAULT_ASSERT_LEVEL
	static constexpr auto DEFAULT_ASSERT_LEVEL = SDL_DEFAULT_ASSERT_LEVEL;
	#undef SDL_DEFAULT_ASSERT_LEVEL
#endif

#ifdef SDL_TriggerBreakpoint
[[maybe_unused]] static auto
TriggerBreakpoint()
{
	SDL_TriggerBreakpoint();
	#undef SDL_TriggerBreakpoint
}
#endif

#undef SDL_FILE
#undef SDL_LINE

// These were the result of following the wrong name conventions, so I won't even bother re-implementing them.
#undef SDL_assert_state
#undef SDL_assert_data
