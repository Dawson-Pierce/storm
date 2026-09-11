#include <storm/models/GGIW2D.hpp>

namespace storm {
    GGIW2D::GGIW2D(
        double a, 
        double b, 
        const Vector& mean, 
        const Matrix& covariance, 
        double v, 
        const Matrix& V
    ) 
      : a_(a), 
        b_(b), 
        m_(mean), 
        P_(covariance), 
        v_(v), 
        V_(V) 
        {

        }

    double GGIW2D::alpha() const{
        return a_;
    }
    double GGIW2D::beta() const{
        return b_;
    }
    const Vector& GGIW2D::mean() const{
        return m_;
    }
    const Matrix& GGIW2D::covariance() const{
        return P_;
    }
    double GGIW2D::IWdof() const{
        return v_;
    }
    const Matrix& GGIW2D::IWshape() const{
        return V_;
    } 

}
