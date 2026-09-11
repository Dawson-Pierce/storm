#include <storm/models/GGIW.hpp>

namespace storm {
    GGIW::GGIW(
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

    double GGIW::alpha() const{
        return a_;
    }
    double GGIW::beta() const{
        return b_;
    }
    const Vector& GGIW::mean() const{
        return m_;
    }
    const Matrix& GGIW::covariance() const{
        return P_;
    }
    double GGIW::IWdof() const{
        return v_;
    }
    const Matrix& GGIW::IWshape() const{
        return V_;
    } 

}