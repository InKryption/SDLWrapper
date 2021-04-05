#ifndef INK_SDLWRAPPER_ARITHMETIC_DEPENDENTS_WRAPPER_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_ARITHMETIC_DEPENDENTS_WRAPPER_HEADER_FILE_GUARD

#include <concepts>
#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	namespace detail {
		
		template<typename T> concept
		arithmetic = std::same_as<T, int> || std::same_as<T, float>;
		
		template<arithmetic T> struct geometry_impl;
		
		template<> struct geometry_impl<int> {
			
			using Point = internal::SDL_Point;
			using Rect = internal::SDL_Rect;
			
			static constexpr auto& RenderDrawPoint = internal::SDL_RenderDrawPoint;
			static constexpr auto& RenderDrawPoints = internal::SDL_RenderDrawPoints;
			
			static constexpr auto& RenderDrawLine = internal::SDL_RenderDrawLine;
			static constexpr auto& RenderDrawLines = internal::SDL_RenderDrawLines;
			
			static constexpr auto& RenderDrawRect = internal::SDL_RenderDrawRect;
			static constexpr auto& RenderDrawRects = internal::SDL_RenderDrawRects;
			
			static constexpr auto& RenderFillRect = internal::SDL_RenderFillRect;
			static constexpr auto& RenderFillRects = internal::SDL_RenderFillRects;
			
			static constexpr auto& RenderCopy = internal::SDL_RenderCopy;
			static constexpr auto& RenderCopyEx = internal::SDL_RenderCopyEx;
			
		};
		
		template<> struct geometry_impl<float> {
			
			using Point = internal::SDL_FPoint;
			using Rect = internal::SDL_FRect;
			
			static constexpr auto& RenderDrawPoint = internal::SDL_RenderDrawPointF;
			static constexpr auto& RenderDrawPoints = internal::SDL_RenderDrawPointsF;
			
			static constexpr auto& RenderDrawLine = internal::SDL_RenderDrawLineF;
			static constexpr auto& RenderDrawLines = internal::SDL_RenderDrawLinesF;
			
			static constexpr auto& RenderDrawRect = internal::SDL_RenderDrawRectF;
			static constexpr auto& RenderDrawRects = internal::SDL_RenderDrawRectsF;
			
			static constexpr auto& RenderFillRect = internal::SDL_RenderFillRectF;
			static constexpr auto& RenderFillRects = internal::SDL_RenderFillRectsF;
			
			static constexpr auto& RenderCopy = internal::SDL_RenderCopyF;
			static constexpr auto& RenderCopyEx = internal::SDL_RenderCopyExF;
			
		};
		
		template<detail::arithmetic T> using
		Point = typename detail::geometry_impl<T>::Point;
		
		template<detail::arithmetic T> using
		Rect = typename detail::geometry_impl<T>::Rect;
		
	}
	
	template<detail::arithmetic T> struct Point: public detail::Point<T> {
		
		public: using
		type = detail::Point<T>;
		
		public: constexpr
		Point():
		type{0, 0} {}
		
		public: constexpr
		Point(T x, T y):
		type{x, y} {}
		
		public: constexpr
		Point(Point const& p):
		type{p.x, p.y} {}
		
		public: constexpr
		Point(type const& p):
		type{p.x, p.y} {}
		
		public: template<typename P_Like> requires requires(P_Like pL) {
			{ get<0>(pL) } -> std::convertible_to<T>;
			{ get<1>(pL) } -> std::convertible_to<T>;
		} constexpr
		Point(P_Like const& pL):
		type{get<0>(pL), get<1>(pL)} {}
		
		public: template<typename P_Like> requires requires(P_Like pL) {
			{ pL.x } -> std::convertible_to<T>;
			{ pL.y } -> std::convertible_to<T>;
		} constexpr
		Point(P_Like const& pL):
		type{pL.x, pL.y} {}
		
	};
	
	template<detail::arithmetic T> struct Rect: public detail::Rect<T> {
		
	};
	
}

#endif
