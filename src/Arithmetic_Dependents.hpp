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
	
	// Generic implementation of an XY point that is constructible from any pair-like or XY-Point-like structure.
	// e.g. std::tuple<int, float>, std::pair<double, int>, struct Vec { int x; int y; }, etc.
	template<detail::arithmetic T>
	struct Point: public detail::Point<T> {
		
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
			{ pL.x } -> std::convertible_to<T>;
			{ pL.y } -> std::convertible_to<T>;
		} constexpr
		Point(P_Like const& pL):
		type{pL.x, pL.y} {}
		
		public: template<typename P_Like> requires requires(P_Like pL) {
			{ get<0>(pL) } -> std::convertible_to<T>;
			{ get<1>(pL) } -> std::convertible_to<T>;
		}
		|| requires(P_Like pL) {
			{ pL.x } -> std::convertible_to<T>;
			{ pL.y } -> std::convertible_to<T>;
		} constexpr
		Point(P_Like const& pL):
		type{get<0>(pL), get<1>(pL)} {}
		
	};
	
	template<detail::arithmetic T>
	struct Rect: public detail::Rect<T> {
		
		public: using
		type = detail::Rect<T>;
		
		public: constexpr
		Rect():
		type{0, 0, 0, 0} {}
		
		public: constexpr
		Rect(T x, T y, T w, T h):
		type{x, y, w, h} {}
		
		public: constexpr
		Rect(Point<T> const& absolute_point, Point<T> const& relative_point):
		type{absolute_point.x, absolute_point.y, relative_point.x, relative_point.y} {}
		
		public: constexpr
		Rect(Point<T> const& absolute_point, T w, T h):
		type{absolute_point.x, absolute_point.y, w, h} {}
		
		public: constexpr
		Rect(T x, T y, Point<T> const& relative_point):
		type{x, y, relative_point.x, relative_point.y} {}
		
		public: template<typename R_Like> requires requires(R_Like rL) {
			{ rL.x } -> std::convertible_to<T>;
			{ rL.y } -> std::convertible_to<T>;
			{ rL.w } -> std::convertible_to<T>;
			{ rL.h } -> std::convertible_to<T>;
		} constexpr
		Rect(R_Like const& rL):
		type{rL.x, rL.y, rL.w, rL.h} {}
		
		public: template<typename R_Like> requires requires(R_Like rL) {
			{ rL.x } -> std::convertible_to<T>;
			{ rL.y } -> std::convertible_to<T>;
			{ rL.w } -> std::convertible_to<T>;
			{ rL.h } -> std::convertible_to<T>;
		}
		|| requires(R_Like rL) {
			{ get<0>(rL) } -> std::convertible_to<T>;
			{ get<1>(rL) } -> std::convertible_to<T>;
			{ get<2>(rL) } -> std::convertible_to<T>;
			{ get<3>(rL) } -> std::convertible_to<T>;
		} constexpr
		Rect(R_Like const& rL):
		type{get<0>(rL), get<1>(rL), get<2>(rL), get<3>(rL)} {}
		
	};
	
}

#endif
