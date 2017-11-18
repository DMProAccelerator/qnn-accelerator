#pragma once
#include <cstdint>
#include <cstdlib>

typedef struct PackedMatrix {
  void* baseAddr;
  uint32_t channels;
  uint32_t bit_depth;
  uint32_t rows;
  uint32_t columns;
  bool is_signed;
} PackedMatrix;

typedef struct PackedConvolutionFilters {
  void* base_addr;
  uint32_t input_channels;
  uint32_t output_channels;
  uint32_t bit_depth;
  uint32_t window_size;
} PackedConvolutionFilters;

typedef struct ResultMatrix {
  void* baseAddr;
  uint32_t channels;
  uint32_t rows;
  uint32_t columns;
  bool is_signed;
} ResultMatrix;

void image_to_packed_image(void* _platform, int8_t* arr, PackedMatrix* m);

void matrix_to_packed_matrix(void* _platform, int64_t* arr, size_t len, PackedMatrix* m);

void filters_to_packed_filters(void* _platform, int8_t* arr, PackedConvolutionFilters* m);

void result_matrix_to_matrix(void* _platform, ResultMatrix* r, int64_t* arr, size_t len);

//void packed_matrix_to_matrix(PackedMatrix* m, int64_t* arr, size_t len);
