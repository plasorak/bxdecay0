// Copyright 1995-2016 V.I. Tretyak
// Copyright 2011-2017 F. Mauger
//
// This program is free software: you  can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free  Software Foundation, either  version 3 of the  License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

// Ourselves:
#include <bxdecay0/Xe129m.h>

// Standard library:
#include <sstream>
#include <stdexcept>
#include <cmath>

// This project:
#include <bxdecay0/i_random.h>
#include <bxdecay0/event.h>
#include <bxdecay0/alpha.h>
#include <bxdecay0/gamma.h>
#include <bxdecay0/electron.h>
#include <bxdecay0/positron.h>
#include <bxdecay0/particle.h>
#include <bxdecay0/pair.h>
#include <bxdecay0/nucltransK.h>
#include <bxdecay0/nucltransKL.h>
#include <bxdecay0/nucltransKLM.h>
#include <bxdecay0/nucltransKLM_Pb.h>
#include <bxdecay0/beta.h>
#include <bxdecay0/beta1.h>
#include <bxdecay0/beta2.h>
#include <bxdecay0/beta_1fu.h>
#include <bxdecay0/PbAtShell.h>

namespace bxdecay0 {

  void Xe129m(i_random & prng_,
              event & event_,
              const double tcnuc_,
              double & tdnuc_)
  {
    //double t;
    double tdlev;
    double tclev;
    double thlev;
    double thnuc;
    // Scheme of Xe129m decay (NDS 77(1996)631 and ENSDF at NNDC site on
    // 13.11.2007).
    // Input : tcnuc_ - time of creation of nucleus (sec)
    // Output: tdnuc_ - time of decay of nucleus (sec)
    // // common/genevent/tevst,npfull,npgeant(100),pmoment(3,100),// ptime(100).
    // VIT, 13.11.2007.
    thnuc=767232.;
    tdnuc_=tcnuc_-thnuc/std::log(2.)*std::log(prng_());
    tclev=0.;
    ////    label_23600  :
    thlev=0.;
    decay0_nucltransKLM(prng_, event_, 0.197,0.035,13.94,0.005,5.34,0.001,1.52,
                        0.,tclev,thlev,tdlev);
    goto label_40000;
  label_40000  :
    thlev=0.97e-9;
    decay0_nucltransKLM(prng_, event_, 0.040,0.035,10.49,0.005,1.43,0.001,0.39,
                        0.,tclev,thlev,tdlev);
    return;
  }
  // end of Xe129m.f




} // end of namespace bxdecay0

// end of Xe129m.cc
// Local Variables: --
// mode: c++ --
// End: --
