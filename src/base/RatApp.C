#include "RatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"
#include "LaplaceYoung.h"

template <>
InputParameters
validParams<RatApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

RatApp::RatApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  RatApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  RatApp::associateSyntax(_syntax, _action_factory);
}

RatApp::~RatApp() {}

// External entry point for dynamic application loading
extern "C" void
RatApp__registerApps()
{
  RatApp::registerApps();
}
void
RatApp::registerApps()
{
  registerApp(RatApp);
}

// External entry point for dynamic object registration
extern "C" void
RatApp__registerObjects(Factory & factory)
{
  RatApp::registerObjects(factory);
}
void
RatApp::registerObjects(Factory & factory)
{
  registerKernel(LaplaceYoung);
}

// External entry point for dynamic syntax association
extern "C" void
RatApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  RatApp::associateSyntax(syntax, action_factory);
}
void
RatApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
