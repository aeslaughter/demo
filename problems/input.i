[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
[]

[Variables]
  [./unknown]
  [../]
[]

[Kernels]
  [./whatever_you_want]
    type = LaplaceYoung
    variable = unknown
    kappa = 0.5
  [../]
[]

[BCs]
  [./flux]
    type = NeumannBC
    boundary = 'left right top bottom'
    variable = unknown
    value = 0.2
  [../]
[]

[Executioner]
  type = Steady
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]

