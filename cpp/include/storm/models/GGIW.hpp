#pragma once

#include <storm/types.hpp>
#include <string>

namespace storm {
    class GGIW
    {
        public:
            GGIW(
                double a, 
                double b, 
                const Vector& mean, 
                const Matrix& covariance, 
                double v, 
                const Matrix& V
            );

            double alpha() const;
            double beta() const;
            const Vector& mean() const;
            const Matrix& covariance() const;
            double IWdof() const;
            const Matrix& IWshape() const; 

        private:
            double a_; // alpha
            double b_; // beta
            Vector m_; // mean
            Matrix P_; // covariance
            double v_; // inverse-wishart degrees of freedom
            Matrix V_; // inverse-wishart shape matrix
    };
}