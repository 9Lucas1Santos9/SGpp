#include <iostream>

#include <TCanvas.h>
#include <TROOT.h>
#include <TApplication.h>
#include <TStyle.h>
#include "Constantes.hh"

#include "Garfield/ViewField.hh"
#include "Garfield/ViewCell.hh"
#include "Garfield/ComponentAnalyticField.hh"
#include "Garfield/MediumMagboltz.hh"
#include "Garfield/Plotting.hh"

using namespace std;
using namespace Dim;
using namespace Garfield;

int main(int argc, char * argv[]) {

  TApplication app("app", &argc, argv);
  plottingEngine.SetPalette(kGreyScale);

  // Gas mixture.
  MediumMagboltz gas;
  gas.SetComposition("ar", 90, "methane", 10);

  // Define the cell layout.
  ComponentAnalyticField cmp;
  cmp.SetMedium(&gas);

  cmp.AddWire(0., 0., 2 * raiofioouro/1, potencialanodo/1, "Anodo"); 

    for (int i = 0; i < n; i++) {
    stringstream valori;
    valori << i;
    string icorrig;
    valori >> icorrig;
    cmp.AddWire(distcatint*cos(i*twopi/60.)/1,distcatint*sin(i*twopi/60.)/1,2*raio/1,potencialcatint/1,
      "CatInt"+icorrig);}

    for (int i = 0; i < n; i++) {
    stringstream valori;
    valori << i;
    string icorrig;
    valori >> icorrig;
    cmp.AddWire(distcatext*cos(i*twopi/60.)/1,distcatext*sin(i*twopi/60.)/1,2*raio/1,potencialcatext/1,
      "CatExt"+icorrig);}

    cmp.AddTube((raioextal+raiointal)/(2*1), potencialal, 0, "Aluminio");

  
  //For plot of electric ou potential field:

  ViewField fieldView;
  ViewCell cellView;
/*
  fieldView.SetComponent(&cmp);
  fieldView.PlotProfile(0,0,0,raioextal,0,0,"e",true); //if you want to graph the electric field
  fieldView.PlotProfile(0,0,0,raioextal,0,0,"v",true); //if you want to graph the potential field
  cellView.SetCanvas(fieldView.GetCanvas());
  cellView.SetComponent(&cmp);
  cellView.SetArea(0, 0, 6, 6);
  cellView.Plot2d();
*/
  /*
  //For 3d "plot" of the detector
  fieldView.SetComponent(&cmp);
  fieldView.PlotContour("v");
  cellView.SetCanvas(fieldView.GetCanvas());
  cellView.SetComponent(&cmp);
  cellView.Plot3d();
  */
  app.Run(true);

}
