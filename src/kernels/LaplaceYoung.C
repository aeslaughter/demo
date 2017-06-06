#include "LaplaceYoung.h"

template <>
InputParameters
validParams<LaplaceYoung>()
{
  InputParameters params = validParams<Diffusion>();
  params.addParam<Real>("kappa", 0.2, "This is kappa, I don't know what it means.");
  params.addClassDescription("This is the LaplaceYoung equation, it's awesome.");
  return params;
}

LaplaceYoung::LaplaceYoung(const InputParameters & parameters) : Diffusion(parameters), _kappa(getParam<Real>("kappa")) {}

Real
LaplaceYoung::computeQpResidual()
{
  return k() * Diffusion::computeQpResidual() + _test[_i][_qp] * _kappa * _u[_qp];
}

Real
LaplaceYoung::computeQpJacobian()
{
  return k() * Diffusion::computeQpJacobian() + _test[_i][_qp] * _kappa * _phi[_j][_qp];
}

Real
LaplaceYoung::k()
{
  return 1./(std::sqrt(1. + _grad_u[_qp] * _grad_u[_qp]));
}
