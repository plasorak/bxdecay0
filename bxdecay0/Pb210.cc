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
#include <bxdecay0/Pb210.h>

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

  void Pb210(i_random & prng_,
             event & event_,
             const double tcnuc_,
             double & tdnuc_)
  {
    double t;
    double tdlev;
    double pbeta;
    double tclev;
    double thlev;
    double thnuc;
    // Scheme of Pb210 decay in accordance with NDS 99(2003)649 and ENSDF at
    // the NNDC site on 6.08.2007.
    // Labels correspond to energies of Bi210 excited levels in keV.
    // Input : tcnuc_ - time of creation of nucleus (sec)
    // Output: tdnuc_ - time of decay of nucleus (sec)
    // // common/genevent/tevst,npfull,npgeant(100),pmoment(3,100),// ptime(100).
    // Beta decays are 1st forbidden (dJ^(dPi)=0^-,1^-)
    // is supposen.
    // VIT, 6.08.2007.
    thnuc=7.0056e8;
    tdnuc_=tcnuc_-thnuc/std::log(2.)*std::log(prng_());
    tclev=0.;
    pbeta=100.*prng_();
    if (pbeta <= 84.) goto label_47;
    goto label_10000;
  label_47  :
    decay0_beta(prng_, event_, 0.0170,83.,0.,0.,t);
    ////label_47000  :
    thlev=0.;
    decay0_nucltransKLM(prng_, event_, 0.0465,0.016,14.2,0.004,3.36,0.001,1.14,
                        0.,tclev,thlev,tdlev);
    return;
  label_10000  :
    decay0_beta(prng_, event_, 0.0635,83.,0.,0.,t);
    return;
  }
  // end of Pb210.f




} // end of namespace bxdecay0

// end of Pb210.cc
// Local Variables: --
// mode: c++ --
// End: --
