/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Copyright RIA-LAAS/CNRS, 2010
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * File:      AppreatenceImageSimu.h
 * Project:   RT-Slam
 * Author:    Jean-Marie CODOL
 *
 * Version control
 * ===============
 *
 *  $Id$
 *
 * Description
 * ============
 *
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 * \file AppearanceImageSimu.hpp
 * File defining the simulated appearence.
 * \author jmcodol@laas.fr
 * \ingroup rtslam
 */

#ifndef __AppearenceImageSimu_H__
#define __AppearenceImageSimu_H__

/* --------------------------------------------------------------------- */
/* --- INCLUDE --------------------------------------------------------- */
/* --------------------------------------------------------------------- */

#include "image/Image.hpp"
#include "rtslam/appearanceAbstract.hpp"
#include "boost/shared_ptr.hpp"

namespace jafar {
	namespace rtslam {
		using namespace std;

		class AppearenceImagePoint;
		typedef boost::shared_ptr<AppearenceImagePoint> app_img_pnt_ptr_t;

		/** Appearence for matching
		 * rtslam.
		 *
		 * @ingroup rtslam
		 */
		class AppearenceImagePoint: public AppearanceAbstract {
			public:
				image::Image patch;
				unsigned int patchSum;
				unsigned int patchSquareSum;
			public:
				AppearenceImagePoint(const image::Image& patch);
				AppearenceImagePoint(int width, int height, int depth) : patch(width, height, depth, JfrImage_CS_GRAY) {
					cout << "Created patch with " << width << "x" << height << " pixels; depth: " << depth << "; color space: " << JfrImage_CS_GRAY << endl;
				}
				virtual ~AppearenceImagePoint();

			private:
				void computePatchIntegrals();
		};
	}

}

#endif // #ifndef __AppearenceImageSimu_H__
/*
 * Local variables:
 * mode: c++
 * indent-tabs-mode: t
 * tab-width: 2
 * c-basic-offset: 2
 * End:
 */
