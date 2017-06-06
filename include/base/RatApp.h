#ifndef RATAPP_H
#define RATAPP_H

#include "MooseApp.h"

class RatApp;

template <>
InputParameters validParams<RatApp>();

class RatApp : public MooseApp
{
public:
  RatApp(InputParameters parameters);
  virtual ~RatApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* RATAPP_H */
