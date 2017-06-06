#include "LaplaceYoung.h"

template <>
InputParameters
validParams<LaplaceYoung>()
{
  InputParameters params = validParams<Diffusion>();
  params.addClassDescription("This is the LaplaceYoung equation, it's awesome.");
  return params;
}

LaplaceYoung::LaplaceYoung(const InputParameters & parameters) : Diffusion(parameters) {}

Real
LaplaceYoung::computeQpResidual()
{
  Real kappa = 0.2;
  return k() * Diffusion::computeQpResidual() + _test[_i][_qp] * kappa * _u[_qp];
}

Real
LaplaceYoung::computeQpJacobian()
{
  Real kappa = 0.2;
  return k() * Diffusion::computeQpJacobian() + _test[_i][_qp] * kappa * _phi[_j][_qp];
}

Real
LaplaceYoung::k()
{
  return 1./(std::sqrt(1. + _grad_u[_qp] * _grad_u[_qp]));
}
