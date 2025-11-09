#include "helper.h"
#include <cstdint>
#include <cstdio>
#include <immintrin.h>
#include <limits>

typedef float f32;
typedef double f64;
typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;

static void avx_f64_mult()
{
	using type = f64;
	puts("Задание 2. f64 C = A * B");
	type a[4] = {3.5, 111.0, -std::numeric_limits<type>::infinity(), -10.0};
	type b[4] = {0.5, std::numeric_limits<type>::min(), -0.1, 12.3};
	type c[4] = {0.0, 0.0, 0.0, 0.0};

	printf("a: ");
	print_array(std::span{a, 4});
	printf("b: ");
	print_array(std::span{b, 4});

	auto vec_a = _mm256_load_pd(a);
	auto vec_b = _mm256_load_pd(b);
	auto vec_c = _mm256_mul_pd(vec_a, vec_b);
	_mm256_store_pd(c, vec_c);

	printf("c: ");
	print_array(std::span{c, 4});
}

static void avx_f32_div()
{
	using type = f32;
	puts("Задание 1. f32 C = A / B");
	type a[8] = {
		1.1f,	13.37f, 3.5f, 1.0f,
		-10.0f, 8.8f,	0.0f, std::numeric_limits<type>::quiet_NaN()};

	type b[8] = {2.28f,
		     54.6f,
		     0.0f,
		     99099.9f,
		     -0.0f,
		     std::numeric_limits<type>::max(),
		     std::numeric_limits<type>::min(),
		     0.5f};
	type c[8] = {};

	printf("a: ");
	print_array(std::span{a, 8});
	printf("b: ");
	print_array(std::span{b, 8});

	auto vec_a = _mm256_load_ps(a);
	auto vec_b = _mm256_load_ps(b);
	auto vec_c = _mm256_div_ps(vec_a, vec_b);
	_mm256_store_ps(c, vec_c);

	printf("c: ");
	print_array(std::span{c, 8});
}

int main()
{

	avx_f32_div();
	std::println();

	avx_f64_mult();

	puts("Нажмите любую кнопку для завершения");
	(void)getchar();
	return 0;
}
