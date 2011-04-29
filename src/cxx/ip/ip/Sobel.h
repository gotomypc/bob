/**
 * @file src/cxx/ip/ip/Sobel.h
 * @author <a href="mailto:Laurent.El-Shafey@idiap.ch">Laurent El Shafey</a> 
 *
 * @brief This file provides a class to process images with the Sobel operator
 */

#ifndef TORCH5SPRO_IP_SOBEL_H
#define TORCH5SPRO_IP_SOBEL_H

#include "core/array_assert.h"
#include "core/cast.h"
#include "ip/Exception.h"
#include "sp/convolution.h"

namespace Torch {
/**
 * \ingroup libip_api
 * @{
 *
 */
  namespace ip {

  /**
   * @brief This class can be used to process images with the Sobel operator
  */
	class Sobel
	{
  	public:

	  	/**
        * @brief Constructor: generates the Sobel kernel
        */
	    Sobel(const bool up_positive=false, const bool left_positive=false, 
        const enum sp::Convolution::SizeOption size_opt=sp::Convolution::Same,
        const enum sp::Convolution::BorderOption 
          border_opt=sp::Convolution::Mirror);

	  	/**
        * @brief Destructor
        */
	    virtual ~Sobel() {}

	  	/**
        * @brief Process a 2D blitz Array/Image by applying the Sobel operator
        *   The resulting 3D array will contain two planes:
        *     - The first one for the convolution with the y-kernel
        *     - The second one for the convolution with the x-kernel
        * @warning The selected type should be signed (e.g. int64_t or double)
        */
	    template <typename T> void operator()(const blitz::Array<T,2>& src, 
        blitz::Array<T,3>& dst);

	  private:
	  	/**
        * @brief Generates the Sobel kernels
        */
  		void computeKernels();

      // Attributes
      blitz::Array<double, 2> m_kernel_y;
      blitz::Array<double, 2> m_kernel_x;
      bool m_up_positive;
      bool m_left_positive;
      enum sp::Convolution::SizeOption m_size_opt;
      enum sp::Convolution::BorderOption m_border_opt;
	};

  template <typename T> 
  void Sobel::operator()(const blitz::Array<T,2>& src, blitz::Array<T,3>& dst)
  { 
    // Check that dst has two planes
    if( dst.extent(0) != 2 )
      throw Torch::ip::Exception();
    // Check that dst has zero bases
    Torch::core::array::assertZeroBase(dst);

    // Define slices for y and x
    blitz::Array<T,2> dst_y = dst(0, blitz::Range::all(), blitz::Range::all());
    blitz::Array<T,2> dst_x = dst(1, blitz::Range::all(), blitz::Range::all());
    // TODO: improve the way we deal with types
    Torch::sp::convolve(src, Torch::core::cast<T>(m_kernel_y), dst_y, m_size_opt, m_border_opt);
    Torch::sp::convolve(src, Torch::core::cast<T>(m_kernel_x), dst_x, m_size_opt, m_border_opt);
  }

}}

#endif /* TORCH5SPRO_SOBEL_H */
