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
  [../]
[]

[BCs]
  [./flux]
    type = NeumannBC
    boundary = 'left right top bottom'
    value = 0.2
    variable = unknown
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
