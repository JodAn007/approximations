#include <limits.h>
#define INVALID_FUNCTION INT_MIN

int rootGIFFunc(int (*func)(int), int k, int rangeStart, int rangeEnd){ // Uses binary search to find GIF of solution of func(x) = k
									// (func is an increasing function for all x > rangeStart)
	int rangeMiddle = (rangeStart+rangeEnd)/2;
	if (func(rangeMiddle+1) > k && func(rangeMiddle) <= k) return rangeMiddle; // Well, here's one big fucking issue: what if func output goes out of 64-bit range?
										   // Well, I guess that's a headache for whoever decided the rangeStart and rangeEnd values(me).
	if (func(rangeMiddle) > k) return rootGIFFunc(func, k, rangeStart, rangeMiddle); //maybe I should put +1 after division not sure
	if (func(rangeMiddle) < k) return rootGIFFunc(func, k, rangeMiddle, rangeEnd);
	return INVALID_FUNCTION; // Because if none of the conditions are satisfied, func(rangeMiddle) = k but func(rangeMiddle) + 1 is not greater than k.
				 // And yes, I know this won't always give the error whenever the function in non-increasing. BUT, it's better than nothing.
				 // Anyways, checking if the function is always increasing would be waaaay too slow. And difficult, frankly. Let's not do that.
				 // (could even be impossible)
				 // Anyways, INVALID_FUNCTION is defined as INT_MIN cuz... well, idk. What SHOULD I return anyways? A struct? Let's not.
}

double rootFunc(double (*func)(double), double k, double rangeStart, double rangeEnd){
	double rangeMiddle = (rangeStart+rangeEnd)/2;
	if (func(rangeMiddle) == k) return rangeMiddle; //Yup, defo gonna lead to precision errors with a lot of functions. Oh well, a problem for future me.
	if (func(rangeMiddle) > k) return rootGIFFunc(func, k, rangeStart, rangeMiddle);
	if (func(rangeMiddle) < k) return rootGIFFunc(func, k, rangeMiddle, rangeEnd);
	return INVALID_FUNCTION; // wtf am I doing this is a double returning function! Ugh.
}
