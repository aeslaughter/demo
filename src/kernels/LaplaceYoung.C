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
  return _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
LaplaceYoung::computeQpJacobian()
{
  return _grad_phi[_j][_qp] * _grad_test[_i][_qp];
}
