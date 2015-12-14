/*CWBoon 2015 */

#pragma once

#include<vector>
#include<core/Shape.hpp>
#include<Eigen/Core>
#include <Eigen/LU> 
#include <Eigen/QR>
#include<lib/base/openmp-accu.hpp>
namespace yade{
class PotentialParticle : public Shape
{

	public:
		
		
		virtual ~PotentialParticle ();

	
	YADE_CLASS_BASE_DOC_ATTRS_CTOR(PotentialParticle,Shape,"Geometry of PotentialParticle.",
		((int, id, 1,, "idNo"))
		((bool, isBoundary, false,, "boundary"))
		((bool, fixedNormal, false,, "use fixed normal"))
		((Vector3r, boundaryNormal, Vector3r::Zero(),,"normal direction of boundary"))
		((bool, AabbMinMax, false,, "aabb"))
		((Vector3r, minAabb, Vector3r::Zero(),,"min from box centre"))
		((Vector3r, maxAabb, Vector3r::Zero(),,"max frin box centre"))
		((Vector3r, minAabbRotated, Vector3r::Zero(),,"min from box centre"))
		((Vector3r, maxAabbRotated, Vector3r::Zero(),,"max frin box centre"))
		((Vector3r, halfSize, Vector3r::Zero(),,"max frin box centre"))
		((Quaternionr , oriAabb, Quaternionr::Identity(),, "r "))
		((Real , r, 0.1,, "r "))
		((Real , R, 1.0,, "R "))
		((Real , k, 0.1,, "k "))
		((vector<Vector3r>, vertices,,,"vertices"))
		((vector<bool> , isBoundaryPlane, ,, "whether it is a boundaryPlane "))
		((vector<double> , a, ,, "a "))
		((vector<double> , b, ,, "b "))
		((vector<double> , c, ,, "c "))
		((vector<double> , d, ,, "d "))
		,
		createIndex(); /*ctor*/
		#if 0
		for (int i=0; i<a.size(); i++){
			Amatrix(i,0) = a[i]; Amatrix(i,1)=b[i]; Amatrix(i,2)=c[i];
			Dmatrix(i,0) = d[i] + r;
	 	}
		#endif
	
	);
	//#endif

	REGISTER_CLASS_INDEX(PotentialParticle,Shape);
	
};
}
using namespace yade; 

REGISTER_SERIALIZABLE(PotentialParticle);

#ifdef __cplusplus
extern "C" {
#endif
	 void dgesv_(const int *N, const int *nrhs, double *Hessian, const int *lda, int *ipiv, double *gradient, const int *ldb, int *info);
	void dsyev_(const char *jobz, const char *uplo, const int *N, double *A, const int *lda, double *W, double *work, int *lwork, int *info);
#ifdef __cplusplus
};
#endif

