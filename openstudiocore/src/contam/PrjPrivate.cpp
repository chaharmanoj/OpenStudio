/**********************************************************************
 *  Copyright (c) 2013, The Pennsylvania State University.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/
#include "PrjPrivate.hpp"

namespace openstudio {
namespace contam {
namespace prj {

ZonePrivate::ZonePrivate(int nr,unsigned int flags,int ps,int pc,int pk,int pl,RX relHt,RX Vol,RX T0,RX P0,STRING name,int color,int u_Ht,int u_V,int u_T,int u_P,int cdaxis,int cfd,STRING cfdname,RX X1,RX Y1,RX H1,RX X2,RX Y2,RX H2,RX celldx,RX axialD,int u_aD,int u_L):nr(nr),flags(flags),ps(ps),pc(pc),pk(pk),pl(pl),relHt(relHt),Vol(Vol),T0(T0),P0(P0),name(name),color(color),u_Ht(u_Ht),u_V(u_V),u_T(u_T),u_P(u_P),cdaxis(cdaxis),cfd(cfd),cfdname(cfdname),X1(X1),Y1(Y1),H1(H1),X2(X2),Y2(Y2),H2(H2),celldx(celldx),axialD(axialD),u_aD(u_aD),u_L(u_L)
{}

void ZonePrivate::read(Reader &input)
{
    nr = input.readInt(FILELINE);
    flags = input.readInt(FILELINE);
    ps = input.readInt(FILELINE);
    pc = input.readInt(FILELINE);
    pk = input.readInt(FILELINE);
    pl = input.readInt(FILELINE);
    relHt = input.readNumber<RX>(FILELINE);
    Vol = input.readNumber<RX>(FILELINE);
    T0 = input.readNumber<RX>(FILELINE);
    P0 = input.readNumber<RX>(FILELINE);
    name = input.readString(FILELINE);
    color = input.readInt(FILELINE);
    u_Ht = input.readInt(FILELINE);
    u_V = input.readInt(FILELINE);
    u_T = input.readInt(FILELINE);
    u_P = input.readInt(FILELINE);
    cdaxis = input.readInt(FILELINE);
    cfd = input.readInt(FILELINE);
    if(cfd)
        cfdname = input.readString(FILELINE);
    else if(cdaxis)
    {
        input.readString(FILELINE);  // Read "1D:"
        X1 = input.readNumber<RX>(FILELINE);
        Y1 = input.readNumber<RX>(FILELINE);
        H1 = input.readNumber<RX>(FILELINE);
        X2 = input.readNumber<RX>(FILELINE);
        Y2 = input.readNumber<RX>(FILELINE);
        H2 = input.readNumber<RX>(FILELINE);
        celldx = input.readNumber<RX>(FILELINE);
        axialD = input.readNumber<RX>(FILELINE);
        u_aD = input.readInt(FILELINE);
        u_L = input.readInt(FILELINE);
    }
}

STRING ZonePrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(ps) + ' ' + TO_STRING(pc) + ' '
            + TO_STRING(pk) + ' ' + TO_STRING(pl) + ' ' + TO_STRING(relHt) + ' '
            + TO_STRING(Vol) + ' ' + TO_STRING(T0) + ' ' + TO_STRING(P0) + ' ' + name + ' '
            + TO_STRING(color) + ' ' + TO_STRING(u_Ht) + ' ' + TO_STRING(u_V) + ' ' + TO_STRING(u_T) + ' '
            + TO_STRING(u_P) + ' ' + TO_STRING(cdaxis) + ' ' + TO_STRING(cfd);
    if(cfd)
        string += ' ' + cfdname;
    else if(cdaxis)
        string += TO_STRING(X1) + ' ' + TO_STRING(Y1) + ' ' + TO_STRING(H1) + ' '
                + TO_STRING(X2) + ' ' + TO_STRING(Y2) + ' ' + TO_STRING(H2) + ' '
                + TO_STRING(celldx) + ' ' + TO_STRING(axialD) + ' ' + TO_STRING(u_aD) + ' '
                + TO_STRING(u_L);
    return string+'\n';
}

SpeciesPrivate::SpeciesPrivate(int nr,int sflag,int ntflag,RX molwt,RX mdiam,RX edens,RX decay,RX Dm,RX ccdef,RX Cp,int ucc,int umd,int ued,int udm,int ucp,STRING name,STRING desc):nr(nr),sflag(sflag),ntflag(ntflag),molwt(molwt),mdiam(mdiam),edens(edens),decay(decay),Dm(Dm),ccdef(ccdef),Cp(Cp),ucc(ucc),umd(umd),ued(ued),udm(udm),ucp(ucp),name(name),desc(desc)
{}

void SpeciesPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    sflag = input.read<int>(FILELINE);
    ntflag = input.read<int>(FILELINE);
    molwt = input.readNumber<RX>(FILELINE);
    mdiam = input.readNumber<RX>(FILELINE);
    edens = input.readNumber<RX>(FILELINE);
    decay = input.readNumber<RX>(FILELINE);
    Dm = input.readNumber<RX>(FILELINE);
    ccdef = input.readNumber<RX>(FILELINE);
    Cp = input.readNumber<RX>(FILELINE);
    ucc = input.read<int>(FILELINE);
    umd = input.read<int>(FILELINE);
    ued = input.read<int>(FILELINE);
    udm = input.read<int>(FILELINE);
    ucp = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
}

STRING SpeciesPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(sflag) + ' ' + TO_STRING(ntflag) + ' ' + TO_STRING(molwt) + ' ' + TO_STRING(mdiam) + ' ' + TO_STRING(edens) + ' ' + TO_STRING(decay) + ' ' + TO_STRING(Dm) + ' ' + TO_STRING(ccdef) + ' ' + TO_STRING(Cp) + ' ' + TO_STRING(ucc) + ' ' + TO_STRING(umd) + ' ' + TO_STRING(ued) + ' ' + TO_STRING(udm) + ' ' + TO_STRING(ucp) + ' ' + name + '\n';
    string += desc + '\n';
    return string;
}

AhsPrivate::AhsPrivate(int nr,int zone_r,int zone_s,int path_r,int path_s,int path_x,STRING name,STRING desc):nr(nr),zone_r(zone_r),zone_s(zone_s),path_r(path_r),path_s(path_s),path_x(path_x),name(name),desc(desc)
{}

void AhsPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    zone_r = input.read<int>(FILELINE);
    zone_s = input.read<int>(FILELINE);
    path_r = input.read<int>(FILELINE);
    path_s = input.read<int>(FILELINE);
    path_x = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
}

STRING AhsPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(zone_r) + ' ' + TO_STRING(zone_s) + ' ' + TO_STRING(path_r) + ' ' + TO_STRING(path_s) + ' ' + TO_STRING(path_x) + ' ' + name + '\n';
    string += desc + '\n';
    return string;
}

PathPrivate::PathPrivate(int nr,int flags,int pzn,int pzm,int pe,int pf,int pw,int pa,int ps,int pc,int pld,RX X,RX Y,RX relHt,RX mult,RX wPset,RX wPmod,RX wazm,RX Fahs,RX Xmax,RX Xmin,unsigned int icon,unsigned int dir,int u_Ht,int u_XY,int u_dP,int u_F,int cfd,STRING cfd_name,int cfd_ptype,int cfd_btype,int cfd_capp):nr(nr),flags(flags),pzn(pzn),pzm(pzm),pe(pe),pf(pf),pw(pw),pa(pa),ps(ps),pc(pc),pld(pld),X(X),Y(Y),relHt(relHt),mult(mult),wPset(wPset),wPmod(wPmod),wazm(wazm),Fahs(Fahs),Xmax(Xmax),Xmin(Xmin),icon(icon),dir(dir),u_Ht(u_Ht),u_XY(u_XY),u_dP(u_dP),u_F(u_F),cfd(cfd),cfd_name(cfd_name),cfd_ptype(cfd_ptype),cfd_btype(cfd_btype),cfd_capp(cfd_capp)
{}

void PathPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    flags = input.read<int>(FILELINE);
    pzn = input.read<int>(FILELINE);
    pzm = input.read<int>(FILELINE);
    pe = input.read<int>(FILELINE);
    pf = input.read<int>(FILELINE);
    pw = input.read<int>(FILELINE);
    pa = input.read<int>(FILELINE);
    ps = input.read<int>(FILELINE);
    pc = input.read<int>(FILELINE);
    pld = input.read<int>(FILELINE);
    X = input.readNumber<RX>(FILELINE);
    Y = input.readNumber<RX>(FILELINE);
    relHt = input.readNumber<RX>(FILELINE);
    mult = input.readNumber<RX>(FILELINE);
    wPset = input.readNumber<RX>(FILELINE);
    wPmod = input.readNumber<RX>(FILELINE);
    wazm = input.readNumber<RX>(FILELINE);
    Fahs = input.readNumber<RX>(FILELINE);
    Xmax = input.readNumber<RX>(FILELINE);
    Xmin = input.readNumber<RX>(FILELINE);
    icon = input.read<unsigned int>(FILELINE);
    dir = input.read<unsigned int>(FILELINE);
    u_Ht = input.read<int>(FILELINE);
    u_XY = input.read<int>(FILELINE);
    u_dP = input.read<int>(FILELINE);
    u_F = input.read<int>(FILELINE);
    cfd = input.read<int>(FILELINE);
    if(cfd)
    {
        cfd_name = input.readString(FILELINE);
        cfd_ptype = input.read<int>(FILELINE);
        cfd_btype = input.read<int>(FILELINE);
        cfd_capp = input.read<int>(FILELINE);
    }
}

STRING PathPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(pzn) + ' ' + TO_STRING(pzm) + ' '
            + TO_STRING(pe) + ' ' + TO_STRING(pf) + ' ' + TO_STRING(pw) + ' ' + TO_STRING(pa) + ' '
            + TO_STRING(ps) + ' ' + TO_STRING(pc) + ' ' + TO_STRING(pld) + ' ' + TO_STRING(X) + ' '
            + TO_STRING(Y) + ' ' + TO_STRING(relHt) + ' ' + TO_STRING(mult) + ' ' + TO_STRING(wPset) + ' '
            + TO_STRING(wPmod) + ' ' + TO_STRING(wazm) + ' ' + TO_STRING(Fahs) + ' ' + TO_STRING(Xmax) + ' '
            + TO_STRING(Xmin) + ' ' + TO_STRING(icon) + ' ' + TO_STRING(dir) + ' ' + TO_STRING(u_Ht) + ' '
            + TO_STRING(u_XY) + ' ' + TO_STRING(u_dP) + ' ' + TO_STRING(u_F) + ' ' + TO_STRING(cfd);
    if(cfd)
    {
        string += ' ' + cfd_name + ' ' + TO_STRING(cfd_ptype) + ' ' + TO_STRING(cfd_btype) + ' '
                + TO_STRING(cfd_capp);
    }
    return string + '\n';
}

RunControlPrivate::RunControlPrivate(STRING name,STRING version,int echo,STRING prjdesc,int skheight,int skwidth,int def_units,int def_flows,RX def_T,int udefT,RX rel_N,RX wind_H,int uwH,RX wind_Ao,RX wind_a,RX scale,int uScale,int orgRow,int orgCol,int invYaxis,int showGeom,WeatherData ssWeather,WeatherData wptWeather,STRING WTHpath,STRING CTMpath,STRING CVFpath,STRING DVFpath,STRING WPCfile,STRING EWCfile,STRING WPCdesc,RX X0,RX Y0,RX Z0,RX angle,int u_XYZ,RX epsPath,RX epsSpcs,STRING tShift,STRING dStart,STRING dEnd,int useWPCwp,int useWPCmf,int wpctrig,RX latd,RX lgtd,RX Tznr,RX altd,RX Tgrnd,int utg,int u_a,int sim_af,int afcalc,int afmaxi,RX afrcnvg,RX afacnvg,RX afrelax,int uac2,RX Pres,int uPres,int afslae,int afrseq,int aflmaxi,RX aflcnvg,int aflinit,int Tadj,int sim_mf,int ccmaxi,RX ccrcnvg,RX ccacnvg,RX ccrelax,int uccc,int mfnmthd,int mfnrseq,int mfnmaxi,RX mfnrcnvg,RX mfnacnvg,RX mfnrelax,RX mfngamma,int uccn,int mftmthd,int mftrseq,int mftmaxi,RX mftrcnvg,RX mftacnvg,RX mftrelax,RX mftgamma,int ucct,int mfvmthd,int mfvrseq,int mfvmaxi,RX mfvrcnvg,RX mfvacnvg,RX mfvrelax,int uccv,int mf_solver,int sim_1dz,int sim_1dd,RX celldx,int sim_vjt,int udx,int cvode_mth,RX cvode_rcnvg,RX cvode_acnvg,RX cvode_dtmax,int tsdens,RX tsrelax,int tsmaxi,int cnvgSS,int densZP,int stackD,int dodMdt,STRING date_st,STRING time_st,STRING date_0,STRING time_0,STRING date_1,STRING time_1,STRING time_step,STRING time_list,STRING time_scrn,int restart,STRING rstdate,STRING rsttime,int list,int doDlg,int pfsave,int zfsave,int zcsave,int achvol,int achsave,int abwsave,int cbwsave,int expsave,int ebwsave,int zaasave,int zbwsave,int rzfsave,int rzmsave,int rz1save,int csmsave,int srfsave,int logsave,std::vector<int> save,std::vector<RX> rvals,int BldgFlowZ,int BldgFlowD,int BldgFlowC,int cfd_ctype,RX cfd_convcpl,int cfd_var,int cfd_zref,int cfd_imax,int cfd_dtcmo):name(name),version(version),echo(echo),prjdesc(prjdesc),skheight(skheight),skwidth(skwidth),def_units(def_units),def_flows(def_flows),def_T(def_T),udefT(udefT),rel_N(rel_N),wind_H(wind_H),uwH(uwH),wind_Ao(wind_Ao),wind_a(wind_a),scale(scale),uScale(uScale),orgRow(orgRow),orgCol(orgCol),invYaxis(invYaxis),showGeom(showGeom),ssWeather(ssWeather),wptWeather(wptWeather),WTHpath(WTHpath),CTMpath(CTMpath),CVFpath(CVFpath),DVFpath(DVFpath),WPCfile(WPCfile),EWCfile(EWCfile),WPCdesc(WPCdesc),X0(X0),Y0(Y0),Z0(Z0),angle(angle),u_XYZ(u_XYZ),epsPath(epsPath),epsSpcs(epsSpcs),tShift(tShift),dStart(dStart),dEnd(dEnd),useWPCwp(useWPCwp),useWPCmf(useWPCmf),wpctrig(wpctrig),latd(latd),lgtd(lgtd),Tznr(Tznr),altd(altd),Tgrnd(Tgrnd),utg(utg),u_a(u_a),sim_af(sim_af),afcalc(afcalc),afmaxi(afmaxi),afrcnvg(afrcnvg),afacnvg(afacnvg),afrelax(afrelax),uac2(uac2),Pres(Pres),uPres(uPres),afslae(afslae),afrseq(afrseq),aflmaxi(aflmaxi),aflcnvg(aflcnvg),aflinit(aflinit),Tadj(Tadj),sim_mf(sim_mf),ccmaxi(ccmaxi),ccrcnvg(ccrcnvg),ccacnvg(ccacnvg),ccrelax(ccrelax),uccc(uccc),mfnmthd(mfnmthd),mfnrseq(mfnrseq),mfnmaxi(mfnmaxi),mfnrcnvg(mfnrcnvg),mfnacnvg(mfnacnvg),mfnrelax(mfnrelax),mfngamma(mfngamma),uccn(uccn),mftmthd(mftmthd),mftrseq(mftrseq),mftmaxi(mftmaxi),mftrcnvg(mftrcnvg),mftacnvg(mftacnvg),mftrelax(mftrelax),mftgamma(mftgamma),ucct(ucct),mfvmthd(mfvmthd),mfvrseq(mfvrseq),mfvmaxi(mfvmaxi),mfvrcnvg(mfvrcnvg),mfvacnvg(mfvacnvg),mfvrelax(mfvrelax),uccv(uccv),mf_solver(mf_solver),sim_1dz(sim_1dz),sim_1dd(sim_1dd),celldx(celldx),sim_vjt(sim_vjt),udx(udx),cvode_mth(cvode_mth),cvode_rcnvg(cvode_rcnvg),cvode_acnvg(cvode_acnvg),cvode_dtmax(cvode_dtmax),tsdens(tsdens),tsrelax(tsrelax),tsmaxi(tsmaxi),cnvgSS(cnvgSS),densZP(densZP),stackD(stackD),dodMdt(dodMdt),date_st(date_st),time_st(time_st),date_0(date_0),time_0(time_0),date_1(date_1),time_1(time_1),time_step(time_step),time_list(time_list),time_scrn(time_scrn),restart(restart),rstdate(rstdate),rsttime(rsttime),list(list),doDlg(doDlg),pfsave(pfsave),zfsave(zfsave),zcsave(zcsave),achvol(achvol),achsave(achsave),abwsave(abwsave),cbwsave(cbwsave),expsave(expsave),ebwsave(ebwsave),zaasave(zaasave),zbwsave(zbwsave),rzfsave(rzfsave),rzmsave(rzmsave),rz1save(rz1save),csmsave(csmsave),srfsave(srfsave),logsave(logsave),save(save),rvals(rvals),BldgFlowZ(BldgFlowZ),BldgFlowD(BldgFlowD),BldgFlowC(BldgFlowC),cfd_ctype(cfd_ctype),cfd_convcpl(cfd_convcpl),cfd_var(cfd_var),cfd_zref(cfd_zref),cfd_imax(cfd_imax),cfd_dtcmo(cfd_dtcmo)
{}

void RunControlPrivate::read(Reader &input)
{
    name = input.readString(FILELINE);
    version = input.readString(FILELINE);
    echo = input.read<int>(FILELINE);
    prjdesc = input.readLine(FILELINE);
    skheight = input.read<int>(FILELINE);
    skwidth = input.read<int>(FILELINE);
    def_units = input.read<int>(FILELINE);
    def_flows = input.read<int>(FILELINE);
    def_T = input.readNumber<RX>(FILELINE);
    udefT = input.read<int>(FILELINE);
    rel_N = input.readNumber<RX>(FILELINE);
    wind_H = input.readNumber<RX>(FILELINE);
    uwH = input.read<int>(FILELINE);
    wind_Ao = input.readNumber<RX>(FILELINE);
    wind_a = input.readNumber<RX>(FILELINE);
    scale = input.readNumber<RX>(FILELINE);
    uScale = input.read<int>(FILELINE);
    orgRow = input.read<int>(FILELINE);
    orgCol = input.read<int>(FILELINE);
    invYaxis = input.read<int>(FILELINE);
    showGeom = input.read<int>(FILELINE);
    ssWeather.read(input);
    wptWeather.read(input);
    WTHpath = input.readLine(FILELINE);
    CTMpath = input.readLine(FILELINE);
    CVFpath = input.readLine(FILELINE);
    DVFpath = input.readLine(FILELINE);
    WPCfile = input.readLine(FILELINE);
    EWCfile = input.readLine(FILELINE);
    WPCdesc = input.readLine(FILELINE);
    X0 = input.readNumber<RX>(FILELINE);
    Y0 = input.readNumber<RX>(FILELINE);
    Z0 = input.readNumber<RX>(FILELINE);
    angle = input.readNumber<RX>(FILELINE);
    u_XYZ = input.read<int>(FILELINE);
    epsPath = input.readNumber<RX>(FILELINE);
    epsSpcs = input.readNumber<RX>(FILELINE);
    tShift = input.readString(FILELINE);
    dStart = input.readString(FILELINE);
    dEnd = input.readString(FILELINE);
    useWPCwp = input.read<int>(FILELINE);
    useWPCmf = input.read<int>(FILELINE);
    wpctrig = input.read<int>(FILELINE);
    latd = input.readNumber<RX>(FILELINE);
    lgtd = input.readNumber<RX>(FILELINE);
    Tznr = input.readNumber<RX>(FILELINE);
    altd = input.readNumber<RX>(FILELINE);
    Tgrnd = input.readNumber<RX>(FILELINE);
    utg = input.read<int>(FILELINE);
    u_a = input.read<int>(FILELINE);
    sim_af = input.read<int>(FILELINE);
    afcalc = input.read<int>(FILELINE);
    afmaxi = input.read<int>(FILELINE);
    afrcnvg = input.readNumber<RX>(FILELINE);
    afacnvg = input.readNumber<RX>(FILELINE);
    afrelax = input.readNumber<RX>(FILELINE);
    uac2 = input.read<int>(FILELINE);
    Pres = input.readNumber<RX>(FILELINE);
    uPres = input.read<int>(FILELINE);
    afslae = input.read<int>(FILELINE);
    afrseq = input.read<int>(FILELINE);
    aflmaxi = input.read<int>(FILELINE);
    aflcnvg = input.readNumber<RX>(FILELINE);
    aflinit = input.read<int>(FILELINE);
    Tadj = input.read<int>(FILELINE);
    sim_mf = input.read<int>(FILELINE);
    ccmaxi = input.read<int>(FILELINE);
    ccrcnvg = input.readNumber<RX>(FILELINE);
    ccacnvg = input.readNumber<RX>(FILELINE);
    ccrelax = input.readNumber<RX>(FILELINE);
    uccc = input.read<int>(FILELINE);
    mfnmthd = input.read<int>(FILELINE);
    mfnrseq = input.read<int>(FILELINE);
    mfnmaxi = input.read<int>(FILELINE);
    mfnrcnvg = input.readNumber<RX>(FILELINE);
    mfnacnvg = input.readNumber<RX>(FILELINE);
    mfnrelax = input.readNumber<RX>(FILELINE);
    mfngamma = input.readNumber<RX>(FILELINE);
    uccn = input.read<int>(FILELINE);
    mftmthd = input.read<int>(FILELINE);
    mftrseq = input.read<int>(FILELINE);
    mftmaxi = input.read<int>(FILELINE);
    mftrcnvg = input.readNumber<RX>(FILELINE);
    mftacnvg = input.readNumber<RX>(FILELINE);
    mftrelax = input.readNumber<RX>(FILELINE);
    mftgamma = input.readNumber<RX>(FILELINE);
    ucct = input.read<int>(FILELINE);
    mfvmthd = input.read<int>(FILELINE);
    mfvrseq = input.read<int>(FILELINE);
    mfvmaxi = input.read<int>(FILELINE);
    mfvrcnvg = input.readNumber<RX>(FILELINE);
    mfvacnvg = input.readNumber<RX>(FILELINE);
    mfvrelax = input.readNumber<RX>(FILELINE);
    uccv = input.read<int>(FILELINE);
    mf_solver = input.read<int>(FILELINE);
    sim_1dz = input.read<int>(FILELINE);
    sim_1dd = input.read<int>(FILELINE);
    celldx = input.readNumber<RX>(FILELINE);
    sim_vjt = input.read<int>(FILELINE);
    udx = input.read<int>(FILELINE);
    cvode_mth = input.read<int>(FILELINE);
    cvode_rcnvg = input.readNumber<RX>(FILELINE);
    cvode_acnvg = input.readNumber<RX>(FILELINE);
    cvode_dtmax = input.readNumber<RX>(FILELINE);
    tsdens = input.read<int>(FILELINE);
    tsrelax = input.readNumber<RX>(FILELINE);
    tsmaxi = input.read<int>(FILELINE);
    cnvgSS = input.read<int>(FILELINE);
    densZP = input.read<int>(FILELINE);
    stackD = input.read<int>(FILELINE);
    dodMdt = input.read<int>(FILELINE);
    date_st = input.readString(FILELINE);
    time_st = input.readString(FILELINE);
    date_0 = input.readString(FILELINE);
    time_0 = input.readString(FILELINE);
    date_1 = input.readString(FILELINE);
    time_1 = input.readString(FILELINE);
    time_step = input.readString(FILELINE);
    time_list = input.readString(FILELINE);
    time_scrn = input.readString(FILELINE);
    restart = input.read<int>(FILELINE);
    rstdate = input.readString(FILELINE);
    rsttime = input.readString(FILELINE);
    list = input.read<int>(FILELINE);
    doDlg = input.read<int>(FILELINE);
    pfsave = input.read<int>(FILELINE);
    zfsave = input.read<int>(FILELINE);
    zcsave = input.read<int>(FILELINE);
    achvol = input.read<int>(FILELINE);
    achsave = input.read<int>(FILELINE);
    abwsave = input.read<int>(FILELINE);
    cbwsave = input.read<int>(FILELINE);
    expsave = input.read<int>(FILELINE);
    ebwsave = input.read<int>(FILELINE);
    zaasave = input.read<int>(FILELINE);
    zbwsave = input.read<int>(FILELINE);
    rzfsave = input.read<int>(FILELINE);
    rzmsave = input.read<int>(FILELINE);
    rz1save = input.read<int>(FILELINE);
    csmsave = input.read<int>(FILELINE);
    srfsave = input.read<int>(FILELINE);
    logsave = input.read<int>(FILELINE);
    for(int i=0;i<16;i++)
        save.push_back(input.read<int>(FILELINE));
    int nrvals = input.read<int>(FILELINE);
    for(int i=0;i<nrvals;i++)
        rvals.push_back(input.read<RX>(FILELINE));
    BldgFlowZ = input.read<int>(FILELINE);
    BldgFlowD = input.read<int>(FILELINE);
    BldgFlowC = input.read<int>(FILELINE);
    cfd_ctype = input.read<int>(FILELINE);
    cfd_convcpl = input.readNumber<RX>(FILELINE);
    cfd_var = input.read<int>(FILELINE);
    cfd_zref = input.read<int>(FILELINE);
    cfd_imax = input.read<int>(FILELINE);
    cfd_dtcmo = input.read<int>(FILELINE);
}

STRING RunControlPrivate::write()
{
    STRING string;
    string += name + ' ' + version + ' ' + TO_STRING(echo) + '\n';
    string += prjdesc + '\n';
    string += TO_STRING(skheight) + ' ' + TO_STRING(skwidth) + ' ' + TO_STRING(def_units) + ' ' + TO_STRING(def_flows) + ' ' + TO_STRING(def_T) + ' ' + TO_STRING(udefT) + ' ' + TO_STRING(rel_N) + ' ' + TO_STRING(wind_H) + ' ' + TO_STRING(uwH) + ' ' + TO_STRING(wind_Ao) + ' ' + TO_STRING(wind_a) + '\n';
    string += TO_STRING(scale) + ' ' + TO_STRING(uScale) + ' ' + TO_STRING(orgRow) + ' ' + TO_STRING(orgCol) + ' ' + TO_STRING(invYaxis) + ' ' + TO_STRING(showGeom) + '\n';
    string += ssWeather.write();
    string += wptWeather.write();
    string += WTHpath + '\n';
    string += CTMpath + '\n';
    string += CVFpath + '\n';
    string += DVFpath + '\n';
    string += WPCfile + '\n';
    string += EWCfile + '\n';
    string += WPCdesc + '\n';
    string += TO_STRING(X0) + ' ' + TO_STRING(Y0) + ' ' + TO_STRING(Z0) + ' ' + TO_STRING(angle) + ' ' + TO_STRING(u_XYZ) + '\n';
    string += TO_STRING(epsPath) + ' ' + TO_STRING(epsSpcs) + ' ' + tShift + ' ' + dStart + ' ' + dEnd + ' ' + TO_STRING(useWPCwp) + ' ' + TO_STRING(useWPCmf) + ' ' + TO_STRING(wpctrig) + '\n';
    string += TO_STRING(latd) + ' ' + TO_STRING(lgtd) + ' ' + TO_STRING(Tznr) + ' ' + TO_STRING(altd) + ' ' + TO_STRING(Tgrnd) + ' ' + TO_STRING(utg) + ' ' + TO_STRING(u_a) + '\n';
    string += TO_STRING(sim_af) + ' ' + TO_STRING(afcalc) + ' ' + TO_STRING(afmaxi) + ' ' + TO_STRING(afrcnvg) + ' ' + TO_STRING(afacnvg) + ' ' + TO_STRING(afrelax) + ' ' + TO_STRING(uac2) + ' ' + TO_STRING(Pres) + ' ' + TO_STRING(uPres) + '\n';
    string += TO_STRING(afslae) + ' ' + TO_STRING(afrseq) + ' ' + TO_STRING(aflmaxi) + ' ' + TO_STRING(aflcnvg) + ' ' + TO_STRING(aflinit) + ' ' + TO_STRING(Tadj) + '\n';
    string += TO_STRING(sim_mf) + ' ' + TO_STRING(ccmaxi) + ' ' + TO_STRING(ccrcnvg) + ' ' + TO_STRING(ccacnvg) + ' ' + TO_STRING(ccrelax) + ' ' + TO_STRING(uccc) + '\n';
    string += TO_STRING(mfnmthd) + ' ' + TO_STRING(mfnrseq) + ' ' + TO_STRING(mfnmaxi) + ' ' + TO_STRING(mfnrcnvg) + ' ' + TO_STRING(mfnacnvg) + ' ' + TO_STRING(mfnrelax) + ' ' + TO_STRING(mfngamma) + ' ' + TO_STRING(uccn) + '\n';
    string += TO_STRING(mftmthd) + ' ' + TO_STRING(mftrseq) + ' ' + TO_STRING(mftmaxi) + ' ' + TO_STRING(mftrcnvg) + ' ' + TO_STRING(mftacnvg) + ' ' + TO_STRING(mftrelax) + ' ' + TO_STRING(mftgamma) + ' ' + TO_STRING(ucct) + '\n';
    string += TO_STRING(mfvmthd) + ' ' + TO_STRING(mfvrseq) + ' ' + TO_STRING(mfvmaxi) + ' ' + TO_STRING(mfvrcnvg) + ' ' + TO_STRING(mfvacnvg) + ' ' + TO_STRING(mfvrelax) + ' ' + TO_STRING(uccv) + '\n';
    string += TO_STRING(mf_solver) + ' ' + TO_STRING(sim_1dz) + ' ' + TO_STRING(sim_1dd) + ' ' + TO_STRING(celldx) + ' ' + TO_STRING(sim_vjt) + ' ' + TO_STRING(udx) + '\n';
    string += TO_STRING(cvode_mth) + ' ' + TO_STRING(cvode_rcnvg) + ' ' + TO_STRING(cvode_acnvg) + ' ' + TO_STRING(cvode_dtmax) + '\n';
    string += TO_STRING(tsdens) + ' ' + TO_STRING(tsrelax) + ' ' + TO_STRING(tsmaxi) + ' ' + TO_STRING(cnvgSS) + ' ' + TO_STRING(densZP) + ' ' + TO_STRING(stackD) + ' ' + TO_STRING(dodMdt) + '\n';
    string += date_st + ' ' + time_st + ' ' + date_0 + ' ' + time_0 + ' ' + date_1 + ' ' + time_1 + ' ' + time_step + ' ' + time_list + ' ' + time_scrn + '\n';
    string += TO_STRING(restart) + ' ' + rstdate + ' ' + rsttime + '\n';
    string += TO_STRING(list) + ' ' + TO_STRING(doDlg) + ' ' + TO_STRING(pfsave) + ' ' + TO_STRING(zfsave) + ' ' + TO_STRING(zcsave) + '\n';
    string += TO_STRING(achvol) + ' ' + TO_STRING(achsave) + ' ' + TO_STRING(abwsave) + ' ' + TO_STRING(cbwsave) + ' ' + TO_STRING(expsave) + ' ' + TO_STRING(ebwsave) + ' ' + TO_STRING(zaasave) + ' ' + TO_STRING(zbwsave) + '\n';
    string += TO_STRING(rzfsave) + ' ' + TO_STRING(rzmsave) + ' ' + TO_STRING(rz1save) + ' ' + TO_STRING(csmsave) + ' ' + TO_STRING(srfsave) + ' ' + TO_STRING(logsave) + '\n';
    for(int i=0;i<16;i++)
        string += TO_STRING(save[i]) + ' ';
    string += '\n';
    string += TO_STRING(rvals.size()) + '\n';
    for(unsigned int i=0;i<rvals.size();i++)
        string += TO_STRING(rvals[i]) + ' ';
    string += '\n';
    string += TO_STRING(BldgFlowZ) + ' ' + TO_STRING(BldgFlowD) + ' ' + TO_STRING(BldgFlowC) + '\n';
    string += TO_STRING(cfd_ctype) + ' ' + TO_STRING(cfd_convcpl) + ' ' + TO_STRING(cfd_var) + ' ' + TO_STRING(cfd_zref) + ' ' + TO_STRING(cfd_imax) + ' ' + TO_STRING(cfd_dtcmo) + '\n';
    return string;
}

LevelPrivate::LevelPrivate(int nr,RX refht,RX delht,int u_rfht,int u_dlht,STRING name,std::vector<Icon> icons):nr(nr),refht(refht),delht(delht),u_rfht(u_rfht),u_dlht(u_dlht),name(name),icons(icons)
{}

void LevelPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    refht = input.readNumber<RX>(FILELINE);
    delht = input.readNumber<RX>(FILELINE);
    int nicon = input.read<int>(FILELINE);
    u_rfht = input.read<int>(FILELINE);
    u_dlht = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    for(int i=0;i<nicon;i++)
    {
        Icon object;
        object.read(input);
        icons.push_back(object);
    }

}

STRING LevelPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(refht) + ' ' + TO_STRING(delht) + ' ' + TO_STRING(icons.size()) + ' ' + TO_STRING(u_rfht) + ' ' + TO_STRING(u_dlht) + ' ' + name + '\n';
    for(unsigned int i=0;i<icons.size();i++)
    {
        string += icons[i].write();
    }
    return string;
}

DaySchedulePrivate::DaySchedulePrivate(int nr,int shape,int utyp,int ucnv,STRING name,STRING desc,std::vector<SchedulePoint> points):nr(nr),shape(shape),utyp(utyp),ucnv(ucnv),name(name),desc(desc),points(points)
{}

void DaySchedulePrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    int npts = input.read<int>(FILELINE);
    shape = input.read<int>(FILELINE);
    utyp = input.read<int>(FILELINE);
    ucnv = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    for(int i=0;i<npts;i++)
    {
        SchedulePoint object;
        object.read(input);
        points.push_back(object);
    }

}

STRING DaySchedulePrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(points.size()) + ' ' + TO_STRING(shape) + ' ' + TO_STRING(utyp) + ' ' + TO_STRING(ucnv) + ' ' + name + '\n';
    string += desc + '\n';
    for(unsigned int i=0;i<points.size();i++)
    {
        string += points[i].write();
    }
    return string;
}

WeekSchedulePrivate::WeekSchedulePrivate(int nr,int utyp,int ucnv,STRING name,STRING desc,std::vector<int> j):nr(nr),utyp(utyp),ucnv(ucnv),name(name),desc(desc),j(j)
{}

void WeekSchedulePrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    utyp = input.read<int>(FILELINE);
    ucnv = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    for(int i=0;i<12;i++)
        j.push_back(input.read<int>(FILELINE));
}

STRING WeekSchedulePrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(utyp) + ' ' + TO_STRING(ucnv) + ' ' + name + '\n';
    string += desc + '\n';
    for(int i=0;i<12;i++)
        string += TO_STRING(j[i]) + ' ';
    string += '\n';
    return string;
}

WindPressureProfilePrivate::WindPressureProfilePrivate(int nr,int type,STRING name,STRING desc,std::vector<PressureCoefficientPoint> coeffs):nr(nr),type(type),name(name),desc(desc),coeffs(coeffs)
{}

void WindPressureProfilePrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    int npts = input.read<int>(FILELINE);
    type = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    for(int i=0;i<npts;i++)
    {
        PressureCoefficientPoint object;
        object.read(input);
        coeffs.push_back(object);
    }

}

STRING WindPressureProfilePrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(coeffs.size()) + ' ' + TO_STRING(type) + ' ' + name + '\n';
    string += desc + '\n';
    for(unsigned int i=0;i<coeffs.size();i++)
    {
        string += coeffs[i].write();
    }
    return string;
}


CtrlDatPrivate::CtrlDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc)
{}

void CtrlDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
}

std::string CtrlDatPrivate::write()
{
    std::string string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    return string;
}

SnsDatPrivate::SnsDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,RX offset,RX scale,RX tau,RX oldsig,int source,int type,int measure,RX X,RX Y,RX relHt,STRING units,STRING species):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),offset(offset),scale(scale),tau(tau),oldsig(oldsig),source(source),type(type),measure(measure),X(X),Y(Y),relHt(relHt),units(units),species(species)
{}

void SnsDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    offset = input.readNumber<RX>(FILELINE);
    scale = input.readNumber<RX>(FILELINE);
    tau = input.readNumber<RX>(FILELINE);
    oldsig = input.readNumber<RX>(FILELINE);
    source = input.read<int>(FILELINE);
    type = input.read<int>(FILELINE);
    measure = input.read<int>(FILELINE);
    X = input.readNumber<RX>(FILELINE);
    Y = input.readNumber<RX>(FILELINE);
    relHt = input.readNumber<RX>(FILELINE);
    units = input.readString(FILELINE);
    species = input.readString(FILELINE);
}

STRING SnsDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(offset) + ' ' + TO_STRING(scale) + ' ' + TO_STRING(tau) + ' ' + TO_STRING(oldsig) + ' ' + TO_STRING(source) + ' ' + TO_STRING(type) + ' ' + TO_STRING(measure) + ' ' + TO_STRING(X) + ' ' + TO_STRING(Y) + ' ' + TO_STRING(relHt) + ' ' + units + ' ' + species + '\n';
    return string;
}

void SnsDatPrivate::readDetails(Reader &input)
{
    offset = input.readNumber<RX>(FILELINE);
    scale = input.readNumber<RX>(FILELINE);
    tau = input.readNumber<RX>(FILELINE);
    oldsig = input.readNumber<RX>(FILELINE);
    source = input.read<int>(FILELINE);
    type = input.read<int>(FILELINE);
    measure = input.read<int>(FILELINE);
    X = input.readNumber<RX>(FILELINE);
    Y = input.readNumber<RX>(FILELINE);
    relHt = input.readNumber<RX>(FILELINE);
    units = input.readString(FILELINE);
    species = input.readString(FILELINE);
}

SchDatPrivate::SchDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,int ps):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),ps(ps)
{}

void SchDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    ps = input.read<int>(FILELINE);
}

STRING SchDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(ps) + '\n';
    return string;
}

void SchDatPrivate::readDetails(Reader &input)
{
    ps = input.read<int>(FILELINE);
}

SetDatPrivate::SetDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,RX value):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),value(value)
{}

void SetDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    value = input.readNumber<RX>(FILELINE);
}

STRING SetDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(value) + '\n';
    return string;
}

void SetDatPrivate::readDetails(Reader &input)
{
    value = input.readNumber<RX>(FILELINE);
}

CdvDatPrivate::CdvDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,STRING valuename):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),valuename(valuename)
{}

void CdvDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    valuename = input.readLine(FILELINE);
}

STRING CdvDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += valuename + '\n';
    return string;
}

void CdvDatPrivate::readDetails(Reader &input)
{
    valuename = input.readLine(FILELINE);
}

LogDatPrivate::LogDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,RX offset,RX scale,int udef,STRING header,STRING units):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),offset(offset),scale(scale),udef(udef),header(header),units(units)
{}

void LogDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    offset = input.readNumber<RX>(FILELINE);
    scale = input.readNumber<RX>(FILELINE);
    udef = input.read<int>(FILELINE);
    header = input.readString(FILELINE);
    units = input.readString(FILELINE);
}

STRING LogDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(offset) + ' ' + TO_STRING(scale) + ' ' + TO_STRING(udef) + ' ' + header + ' ' + units + '\n';
    return string;
}

void LogDatPrivate::readDetails(Reader &input)
{
    offset = input.readNumber<RX>(FILELINE);
    scale = input.readNumber<RX>(FILELINE);
    udef = input.read<int>(FILELINE);
    header = input.readString(FILELINE);
    units = input.readString(FILELINE);
}

ModDatPrivate::ModDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,RX offset,RX scale):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),offset(offset),scale(scale)
{}

void ModDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    offset = input.readNumber<RX>(FILELINE);
    scale = input.readNumber<RX>(FILELINE);
}

STRING ModDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(offset) + ' ' + TO_STRING(scale) + '\n';
    return string;
}

void ModDatPrivate::readDetails(Reader &input)
{
    offset = input.readNumber<RX>(FILELINE);
    scale = input.readNumber<RX>(FILELINE);
}

HysDatPrivate::HysDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,RX slack,RX slope,RX oldsig):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),slack(slack),slope(slope),oldsig(oldsig)
{}

void HysDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    slack = input.readNumber<RX>(FILELINE);
    slope = input.readNumber<RX>(FILELINE);
    oldsig = input.readNumber<RX>(FILELINE);
}

STRING HysDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(slack) + ' ' + TO_STRING(slope) + ' ' + TO_STRING(oldsig) + '\n';
    return string;
}

void HysDatPrivate::readDetails(Reader &input)
{
    slack = input.readNumber<RX>(FILELINE);
    slope = input.readNumber<RX>(FILELINE);
    oldsig = input.readNumber<RX>(FILELINE);
}

DlsDatPrivate::DlsDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,int dsincr,int dsdecr):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),dsincr(dsincr),dsdecr(dsdecr)
{}

void DlsDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    dsincr = input.read<int>(FILELINE);
    dsdecr = input.read<int>(FILELINE);
}

STRING DlsDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(dsincr) + ' ' + TO_STRING(dsdecr) + '\n';
    return string;
}

void DlsDatPrivate::readDetails(Reader &input)
{
    dsincr = input.read<int>(FILELINE);
    dsdecr = input.read<int>(FILELINE);
}

DlxDatPrivate::DlxDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,int tauincr,int taudecr):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),tauincr(tauincr),taudecr(taudecr)
{}

void DlxDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    tauincr = input.read<int>(FILELINE);
    taudecr = input.read<int>(FILELINE);
}

STRING DlxDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(tauincr) + ' ' + TO_STRING(taudecr) + '\n';
    return string;
}

void DlxDatPrivate::readDetails(Reader &input)
{
    tauincr = input.read<int>(FILELINE);
    taudecr = input.read<int>(FILELINE);
}

RavDatPrivate::RavDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,int tspan):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),tspan(tspan)
{}

void RavDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    tspan = input.read<int>(FILELINE);
}

STRING RavDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(tspan) + '\n';
    return string;
}

void RavDatPrivate::readDetails(Reader &input)
{
    tspan = input.read<int>(FILELINE);
}

SumAvgPrivate::SumAvgPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,std::vector<int> pc):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),pc(pc)
{}

void SumAvgPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    int npcs = input.read<int>(FILELINE);
    for(int i=0;i<npcs;i++)
        pc.push_back(input.read<int>(FILELINE));
}

STRING SumAvgPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(pc.size()) + '\n';
    for(unsigned int i=0;i<pc.size();i++)
        string += TO_STRING(pc[i]) + ' ';
    string += '\n';
    return string;
}

void SumAvgPrivate::readDetails(Reader &input)
{
    int npcs = input.read<int>(FILELINE);
    for(int i=0;i<npcs;i++)
        pc.push_back(input.read<int>(FILELINE));
}

BanDatPrivate::BanDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,RX band):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),band(band)
{}

void BanDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    band = input.readNumber<RX>(FILELINE);
}

STRING BanDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(band) + '\n';
    return string;
}

void BanDatPrivate::readDetails(Reader &input)
{
    band = input.readNumber<RX>(FILELINE);
}

PcDatPrivate::PcDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,RX kp):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),kp(kp)
{}

void PcDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    kp = input.readNumber<RX>(FILELINE);
}

STRING PcDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(kp) + '\n';
    return string;
}

void PcDatPrivate::readDetails(Reader &input)
{
    kp = input.readNumber<RX>(FILELINE);
}

PicDatPrivate::PicDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,RX kp,RX ki,RX oldsig,RX olderr):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),kp(kp),ki(ki),oldsig(oldsig),olderr(olderr)
{}

void PicDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    kp = input.readNumber<RX>(FILELINE);
    ki = input.readNumber<RX>(FILELINE);
    oldsig = input.readNumber<RX>(FILELINE);
    olderr = input.readNumber<RX>(FILELINE);
}

STRING PicDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(kp) + ' ' + TO_STRING(ki) + ' ' + TO_STRING(oldsig) + ' ' + TO_STRING(olderr) + '\n';
    return string;
}

void PicDatPrivate::readDetails(Reader &input)
{
    kp = input.readNumber<RX>(FILELINE);
    ki = input.readNumber<RX>(FILELINE);
    oldsig = input.readNumber<RX>(FILELINE);
    olderr = input.readNumber<RX>(FILELINE);
}

SupDatPrivate::SupDatPrivate(int nr,STRING dataType,int seqnr,unsigned int flags,int inreq,int n1,int n2,STRING name,STRING desc,int def,int se,int in,int out):nr(nr),dataType(dataType),seqnr(seqnr),flags(flags),inreq(inreq),n1(n1),n2(n2),name(name),desc(desc),def(def),se(se),in(in),out(out)
{}

void SupDatPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    seqnr = input.read<int>(FILELINE);
    flags = input.read<unsigned int>(FILELINE);
    inreq = input.read<int>(FILELINE);
    n1 = input.read<int>(FILELINE);
    n2 = input.read<int>(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    def = input.read<int>(FILELINE);
    se = input.read<int>(FILELINE);
    in = input.read<int>(FILELINE);
    out = input.read<int>(FILELINE);
}

STRING SupDatPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + dataType + '\n';
    string += TO_STRING(seqnr) + ' ' + TO_STRING(flags) + ' ' + TO_STRING(inreq) + ' ' + TO_STRING(n1) + ' ' + TO_STRING(n2) + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(def) + ' ' + TO_STRING(se) + ' ' + TO_STRING(in) + ' ' + TO_STRING(out) + '\n';
    return string;
}

void SupDatPrivate::readDetails(Reader &input)
{
    def = input.read<int>(FILELINE);
    se = input.read<int>(FILELINE);
    in = input.read<int>(FILELINE);
    out = input.read<int>(FILELINE);
}


PlrOrfPrivate::PlrOrfPrivate(int nr,int icon,STRING name,STRING desc,RX lam,RX turb,RX expt,RX area,RX dia,RX coef,RX Re,int u_A,int u_D):nr(nr),icon(icon),name(name),desc(desc),lam(lam),turb(turb),expt(expt),area(area),dia(dia),coef(coef),Re(Re),u_A(u_A),u_D(u_D)
{}

void PlrOrfPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    STRING dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    area = input.readNumber<RX>(FILELINE);
    dia = input.readNumber<RX>(FILELINE);
    coef = input.readNumber<RX>(FILELINE);
    Re = input.readNumber<RX>(FILELINE);
    u_A = input.read<int>(FILELINE);
    u_D = input.read<int>(FILELINE);
}

STRING PlrOrfPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + " plr_orfc " + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(area) + ' ' + TO_STRING(dia) + ' ' + TO_STRING(coef) + ' ' + TO_STRING(Re) + ' ' + TO_STRING(u_A) + ' ' + TO_STRING(u_D) + '\n';
    return string;
}

void PlrOrfPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    area = input.readNumber<RX>(FILELINE);
    dia = input.readNumber<RX>(FILELINE);
    coef = input.readNumber<RX>(FILELINE);
    Re = input.readNumber<RX>(FILELINE);
    u_A = input.read<int>(FILELINE);
    u_D = input.read<int>(FILELINE);
}

PlrLeakPrivate::PlrLeakPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt,RX coef,RX pres,RX area1,RX area2,RX area3,int u_A1,int u_A2,int u_A3,int u_dP):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt),coef(coef),pres(pres),area1(area1),area2(area2),area3(area3),u_A1(u_A1),u_A2(u_A2),u_A3(u_A3),u_dP(u_dP)
{}

void PlrLeakPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    coef = input.readNumber<RX>(FILELINE);
    pres = input.readNumber<RX>(FILELINE);
    area1 = input.readNumber<RX>(FILELINE);
    area2 = input.readNumber<RX>(FILELINE);
    area3 = input.readNumber<RX>(FILELINE);
    u_A1 = input.read<int>(FILELINE);
    u_A2 = input.read<int>(FILELINE);
    u_A3 = input.read<int>(FILELINE);
    u_dP = input.read<int>(FILELINE);
}

STRING PlrLeakPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(coef) + ' ' + TO_STRING(pres) + ' ' + TO_STRING(area1) + ' ' + TO_STRING(area2) + ' ' + TO_STRING(area3) + ' ' + TO_STRING(u_A1) + ' ' + TO_STRING(u_A2) + ' ' + TO_STRING(u_A3) + ' ' + TO_STRING(u_dP) + '\n';
    return string;
}

void PlrLeakPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    coef = input.readNumber<RX>(FILELINE);
    pres = input.readNumber<RX>(FILELINE);
    area1 = input.readNumber<RX>(FILELINE);
    area2 = input.readNumber<RX>(FILELINE);
    area3 = input.readNumber<RX>(FILELINE);
    u_A1 = input.read<int>(FILELINE);
    u_A2 = input.read<int>(FILELINE);
    u_A3 = input.read<int>(FILELINE);
    u_dP = input.read<int>(FILELINE);
}

PlrConnPrivate::PlrConnPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt,RX area,RX coef,int u_A):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt),area(area),coef(coef),u_A(u_A)
{}

void PlrConnPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    area = input.readNumber<RX>(FILELINE);
    coef = input.readNumber<RX>(FILELINE);
    u_A = input.read<int>(FILELINE);
}

STRING PlrConnPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(area) + ' ' + TO_STRING(coef) + ' ' + TO_STRING(u_A) + '\n';
    return string;
}

void PlrConnPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    area = input.readNumber<RX>(FILELINE);
    coef = input.readNumber<RX>(FILELINE);
    u_A = input.read<int>(FILELINE);
}

PlrQcnPrivate::PlrQcnPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt)
{}

void PlrQcnPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
}

STRING PlrQcnPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + '\n';
    return string;
}

void PlrQcnPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
}

PlrFcnPrivate::PlrFcnPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt)
{}

void PlrFcnPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
}

STRING PlrFcnPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + '\n';
    return string;
}

void PlrFcnPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
}

PlrTest1Private::PlrTest1Private(int nr,int icon,STRING name,STRING desc,RX lam,RX turb,RX expt,RX dP,RX Flow,int u_P,int u_F):nr(nr),icon(icon),name(name),desc(desc),lam(lam),turb(turb),expt(expt),dP(dP),Flow(Flow),u_P(u_P),u_F(u_F)
{}

void PlrTest1Private::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    STRING dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    dP = input.readNumber<RX>(FILELINE);
    Flow = input.readNumber<RX>(FILELINE);
    u_P = input.read<int>(FILELINE);
    u_F = input.read<int>(FILELINE);
}

STRING PlrTest1Private::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + " plr_test1 " + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(dP) + ' ' + TO_STRING(Flow) + ' ' + TO_STRING(u_P) + ' ' + TO_STRING(u_F) + '\n';
    return string;
}

void PlrTest1Private::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    dP = input.readNumber<RX>(FILELINE);
    Flow = input.readNumber<RX>(FILELINE);
    u_P = input.read<int>(FILELINE);
    u_F = input.read<int>(FILELINE);
}

PlrTest2Private::PlrTest2Private(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt,RX dP1,RX F1,RX dP2,RX F2,int u_P1,int u_F1,int u_P2,int u_F2):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt),dP1(dP1),F1(F1),dP2(dP2),F2(F2),u_P1(u_P1),u_F1(u_F1),u_P2(u_P2),u_F2(u_F2)
{}

void PlrTest2Private::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    dP1 = input.readNumber<RX>(FILELINE);
    F1 = input.readNumber<RX>(FILELINE);
    dP2 = input.readNumber<RX>(FILELINE);
    F2 = input.readNumber<RX>(FILELINE);
    u_P1 = input.read<int>(FILELINE);
    u_F1 = input.read<int>(FILELINE);
    u_P2 = input.read<int>(FILELINE);
    u_F2 = input.read<int>(FILELINE);
}

STRING PlrTest2Private::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(dP1) + ' ' + TO_STRING(F1) + ' ' + TO_STRING(dP2) + ' ' + TO_STRING(F2) + ' ' + TO_STRING(u_P1) + ' ' + TO_STRING(u_F1) + ' ' + TO_STRING(u_P2) + ' ' + TO_STRING(u_F2) + '\n';
    return string;
}

void PlrTest2Private::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    dP1 = input.readNumber<RX>(FILELINE);
    F1 = input.readNumber<RX>(FILELINE);
    dP2 = input.readNumber<RX>(FILELINE);
    F2 = input.readNumber<RX>(FILELINE);
    u_P1 = input.read<int>(FILELINE);
    u_F1 = input.read<int>(FILELINE);
    u_P2 = input.read<int>(FILELINE);
    u_F2 = input.read<int>(FILELINE);
}

PlrCrackPrivate::PlrCrackPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt,RX length,RX width,int u_L,int u_W):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt),length(length),width(width),u_L(u_L),u_W(u_W)
{}

void PlrCrackPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    length = input.readNumber<RX>(FILELINE);
    width = input.readNumber<RX>(FILELINE);
    u_L = input.read<int>(FILELINE);
    u_W = input.read<int>(FILELINE);
}

STRING PlrCrackPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(length) + ' ' + TO_STRING(width) + ' ' + TO_STRING(u_L) + ' ' + TO_STRING(u_W) + '\n';
    return string;
}

void PlrCrackPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    length = input.readNumber<RX>(FILELINE);
    width = input.readNumber<RX>(FILELINE);
    u_L = input.read<int>(FILELINE);
    u_W = input.read<int>(FILELINE);
}

PlrStairPrivate::PlrStairPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt,RX Ht,RX Area,RX peo,int tread,int u_A,int u_D):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt),Ht(Ht),Area(Area),peo(peo),tread(tread),u_A(u_A),u_D(u_D)
{}

void PlrStairPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    Ht = input.readNumber<RX>(FILELINE);
    Area = input.readNumber<RX>(FILELINE);
    peo = input.readNumber<RX>(FILELINE);
    tread = input.read<int>(FILELINE);
    u_A = input.read<int>(FILELINE);
    u_D = input.read<int>(FILELINE);
}

STRING PlrStairPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(Ht) + ' ' + TO_STRING(Area) + ' ' + TO_STRING(peo) + ' ' + TO_STRING(tread) + ' ' + TO_STRING(u_A) + ' ' + TO_STRING(u_D) + '\n';
    return string;
}

void PlrStairPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    Ht = input.readNumber<RX>(FILELINE);
    Area = input.readNumber<RX>(FILELINE);
    peo = input.readNumber<RX>(FILELINE);
    tread = input.read<int>(FILELINE);
    u_A = input.read<int>(FILELINE);
    u_D = input.read<int>(FILELINE);
}

PlrShaftPrivate::PlrShaftPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt,RX Ht,RX area,RX perim,RX rough,int u_A,int u_D,int u_P,int u_R):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt),Ht(Ht),area(area),perim(perim),rough(rough),u_A(u_A),u_D(u_D),u_P(u_P),u_R(u_R)
{}

void PlrShaftPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    Ht = input.readNumber<RX>(FILELINE);
    area = input.readNumber<RX>(FILELINE);
    perim = input.readNumber<RX>(FILELINE);
    rough = input.readNumber<RX>(FILELINE);
    u_A = input.read<int>(FILELINE);
    u_D = input.read<int>(FILELINE);
    u_P = input.read<int>(FILELINE);
    u_R = input.read<int>(FILELINE);
}

STRING PlrShaftPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(Ht) + ' ' + TO_STRING(area) + ' ' + TO_STRING(perim) + ' ' + TO_STRING(rough) + ' ' + TO_STRING(u_A) + ' ' + TO_STRING(u_D) + ' ' + TO_STRING(u_P) + ' ' + TO_STRING(u_R) + '\n';
    return string;
}

void PlrShaftPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    Ht = input.readNumber<RX>(FILELINE);
    area = input.readNumber<RX>(FILELINE);
    perim = input.readNumber<RX>(FILELINE);
    rough = input.readNumber<RX>(FILELINE);
    u_A = input.read<int>(FILELINE);
    u_D = input.read<int>(FILELINE);
    u_P = input.read<int>(FILELINE);
    u_R = input.read<int>(FILELINE);
}

PlrBdqPrivate::PlrBdqPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX Cp,RX xp,RX Cn,RX xn):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),Cp(Cp),xp(xp),Cn(Cn),xn(xn)
{}

void PlrBdqPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    Cp = input.readNumber<RX>(FILELINE);
    xp = input.readNumber<RX>(FILELINE);
    Cn = input.readNumber<RX>(FILELINE);
    xn = input.readNumber<RX>(FILELINE);
}

STRING PlrBdqPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(Cp) + ' ' + TO_STRING(xp) + ' ' + TO_STRING(Cn) + ' ' + TO_STRING(xn) + '\n';
    return string;
}

void PlrBdqPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    Cp = input.readNumber<RX>(FILELINE);
    xp = input.readNumber<RX>(FILELINE);
    Cn = input.readNumber<RX>(FILELINE);
    xn = input.readNumber<RX>(FILELINE);
}

PlrBdfPrivate::PlrBdfPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX Cp,RX xp,RX Cn,RX xn):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),Cp(Cp),xp(xp),Cn(Cn),xn(xn)
{}

void PlrBdfPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    Cp = input.readNumber<RX>(FILELINE);
    xp = input.readNumber<RX>(FILELINE);
    Cn = input.readNumber<RX>(FILELINE);
    xn = input.readNumber<RX>(FILELINE);
}

STRING PlrBdfPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(Cp) + ' ' + TO_STRING(xp) + ' ' + TO_STRING(Cn) + ' ' + TO_STRING(xn) + '\n';
    return string;
}

void PlrBdfPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    Cp = input.readNumber<RX>(FILELINE);
    xp = input.readNumber<RX>(FILELINE);
    Cn = input.readNumber<RX>(FILELINE);
    xn = input.readNumber<RX>(FILELINE);
}

QfrQabPrivate::QfrQabPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX a,RX b):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),a(a),b(b)
{}

void QfrQabPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    a = input.readNumber<RX>(FILELINE);
    b = input.readNumber<RX>(FILELINE);
}

STRING QfrQabPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(a) + ' ' + TO_STRING(b) + '\n';
    return string;
}

void QfrQabPrivate::readDetails(Reader &input)
{
    a = input.readNumber<RX>(FILELINE);
    b = input.readNumber<RX>(FILELINE);
}

QfrFabPrivate::QfrFabPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX a,RX b):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),a(a),b(b)
{}

void QfrFabPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    a = input.readNumber<RX>(FILELINE);
    b = input.readNumber<RX>(FILELINE);
}

STRING QfrFabPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(a) + ' ' + TO_STRING(b) + '\n';
    return string;
}

void QfrFabPrivate::readDetails(Reader &input)
{
    a = input.readNumber<RX>(FILELINE);
    b = input.readNumber<RX>(FILELINE);
}

QfrCrackPrivate::QfrCrackPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX a,RX b,RX length,RX width,RX depth,int nB,int u_L,int u_W,int u_D):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),a(a),b(b),length(length),width(width),depth(depth),nB(nB),u_L(u_L),u_W(u_W),u_D(u_D)
{}

void QfrCrackPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    a = input.readNumber<RX>(FILELINE);
    b = input.readNumber<RX>(FILELINE);
    length = input.readNumber<RX>(FILELINE);
    width = input.readNumber<RX>(FILELINE);
    depth = input.readNumber<RX>(FILELINE);
    nB = input.read<int>(FILELINE);
    u_L = input.read<int>(FILELINE);
    u_W = input.read<int>(FILELINE);
    u_D = input.read<int>(FILELINE);
}

STRING QfrCrackPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(a) + ' ' + TO_STRING(b) + ' ' + TO_STRING(length) + ' ' + TO_STRING(width) + ' ' + TO_STRING(depth) + ' ' + TO_STRING(nB) + ' ' + TO_STRING(u_L) + ' ' + TO_STRING(u_W) + ' ' + TO_STRING(u_D) + '\n';
    return string;
}

void QfrCrackPrivate::readDetails(Reader &input)
{
    a = input.readNumber<RX>(FILELINE);
    b = input.readNumber<RX>(FILELINE);
    length = input.readNumber<RX>(FILELINE);
    width = input.readNumber<RX>(FILELINE);
    depth = input.readNumber<RX>(FILELINE);
    nB = input.read<int>(FILELINE);
    u_L = input.read<int>(FILELINE);
    u_W = input.read<int>(FILELINE);
    u_D = input.read<int>(FILELINE);
}

QfrTest2Private::QfrTest2Private(int nr,int icon,STRING dataType,STRING name,STRING desc,RX a,RX b,RX dP1,RX F1,RX dP2,RX F2,int u_P1,int u_F1,int u_P2,int u_F2):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),a(a),b(b),dP1(dP1),F1(F1),dP2(dP2),F2(F2),u_P1(u_P1),u_F1(u_F1),u_P2(u_P2),u_F2(u_F2)
{}

void QfrTest2Private::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    a = input.readNumber<RX>(FILELINE);
    b = input.readNumber<RX>(FILELINE);
    dP1 = input.readNumber<RX>(FILELINE);
    F1 = input.readNumber<RX>(FILELINE);
    dP2 = input.readNumber<RX>(FILELINE);
    F2 = input.readNumber<RX>(FILELINE);
    u_P1 = input.read<int>(FILELINE);
    u_F1 = input.read<int>(FILELINE);
    u_P2 = input.read<int>(FILELINE);
    u_F2 = input.read<int>(FILELINE);
}

STRING QfrTest2Private::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(a) + ' ' + TO_STRING(b) + ' ' + TO_STRING(dP1) + ' ' + TO_STRING(F1) + ' ' + TO_STRING(dP2) + ' ' + TO_STRING(F2) + ' ' + TO_STRING(u_P1) + ' ' + TO_STRING(u_F1) + ' ' + TO_STRING(u_P2) + ' ' + TO_STRING(u_F2) + '\n';
    return string;
}

void QfrTest2Private::readDetails(Reader &input)
{
    a = input.readNumber<RX>(FILELINE);
    b = input.readNumber<RX>(FILELINE);
    dP1 = input.readNumber<RX>(FILELINE);
    F1 = input.readNumber<RX>(FILELINE);
    dP2 = input.readNumber<RX>(FILELINE);
    F2 = input.readNumber<RX>(FILELINE);
    u_P1 = input.read<int>(FILELINE);
    u_F1 = input.read<int>(FILELINE);
    u_P2 = input.read<int>(FILELINE);
    u_F2 = input.read<int>(FILELINE);
}

AfeDorPrivate::AfeDorPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt,RX dTmin,RX ht,RX wd,RX cd,int u_T,int u_H,int u_W):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt),dTmin(dTmin),ht(ht),wd(wd),cd(cd),u_T(u_T),u_H(u_H),u_W(u_W)
{}

void AfeDorPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    dTmin = input.readNumber<RX>(FILELINE);
    ht = input.readNumber<RX>(FILELINE);
    wd = input.readNumber<RX>(FILELINE);
    cd = input.readNumber<RX>(FILELINE);
    u_T = input.read<int>(FILELINE);
    u_H = input.read<int>(FILELINE);
    u_W = input.read<int>(FILELINE);
}

STRING AfeDorPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(dTmin) + ' ' + TO_STRING(ht) + ' ' + TO_STRING(wd) + ' ' + TO_STRING(cd) + ' ' + TO_STRING(u_T) + ' ' + TO_STRING(u_H) + ' ' + TO_STRING(u_W) + '\n';
    return string;
}

void AfeDorPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    dTmin = input.readNumber<RX>(FILELINE);
    ht = input.readNumber<RX>(FILELINE);
    wd = input.readNumber<RX>(FILELINE);
    cd = input.readNumber<RX>(FILELINE);
    u_T = input.read<int>(FILELINE);
    u_H = input.read<int>(FILELINE);
    u_W = input.read<int>(FILELINE);
}

DrPl2Private::DrPl2Private(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt,RX dH,RX ht,RX wd,RX cd,int u_H,int u_W):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt),dH(dH),ht(ht),wd(wd),cd(cd),u_H(u_H),u_W(u_W)
{}

void DrPl2Private::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    dH = input.readNumber<RX>(FILELINE);
    ht = input.readNumber<RX>(FILELINE);
    wd = input.readNumber<RX>(FILELINE);
    cd = input.readNumber<RX>(FILELINE);
    u_H = input.read<int>(FILELINE);
    u_W = input.read<int>(FILELINE);
}

STRING DrPl2Private::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(dH) + ' ' + TO_STRING(ht) + ' ' + TO_STRING(wd) + ' ' + TO_STRING(cd) + ' ' + TO_STRING(u_H) + ' ' + TO_STRING(u_W) + '\n';
    return string;
}

void DrPl2Private::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    dH = input.readNumber<RX>(FILELINE);
    ht = input.readNumber<RX>(FILELINE);
    wd = input.readNumber<RX>(FILELINE);
    cd = input.readNumber<RX>(FILELINE);
    u_H = input.read<int>(FILELINE);
    u_W = input.read<int>(FILELINE);
}

AfeCmfPrivate::AfeCmfPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX Flow,int u_F):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),Flow(Flow),u_F(u_F)
{}

void AfeCmfPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    Flow = input.readNumber<RX>(FILELINE);
    u_F = input.read<int>(FILELINE);
}

STRING AfeCmfPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(Flow) + ' ' + TO_STRING(u_F) + '\n';
    return string;
}

void AfeCmfPrivate::readDetails(Reader &input)
{
    Flow = input.readNumber<RX>(FILELINE);
    u_F = input.read<int>(FILELINE);
}

AfeCvfPrivate::AfeCvfPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX Flow,int u_F):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),Flow(Flow),u_F(u_F)
{}

void AfeCvfPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    Flow = input.readNumber<RX>(FILELINE);
    u_F = input.read<int>(FILELINE);
}

STRING AfeCvfPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(Flow) + ' ' + TO_STRING(u_F) + '\n';
    return string;
}

void AfeCvfPrivate::readDetails(Reader &input)
{
    Flow = input.readNumber<RX>(FILELINE);
    u_F = input.read<int>(FILELINE);
}

AfeFanPrivate::AfeFanPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,RX lam,RX turb,RX expt,RX rdens,RX fdf,RX sop,RX off,std::vector<RX> fpc,RX Sarea,int u_Sa,std::vector<FanDataPoint> data):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),lam(lam),turb(turb),expt(expt),rdens(rdens),fdf(fdf),sop(sop),off(off),fpc(fpc),Sarea(Sarea),u_Sa(u_Sa),data(data)
{}

void AfeFanPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    rdens = input.readNumber<RX>(FILELINE);
    fdf = input.readNumber<RX>(FILELINE);
    sop = input.readNumber<RX>(FILELINE);
    off = input.readNumber<RX>(FILELINE);
    for(int i=0;i<4;i++)
        fpc.push_back(input.read<RX>(FILELINE));
    int npts = input.read<int>(FILELINE);
    Sarea = input.readNumber<RX>(FILELINE);
    u_Sa = input.read<int>(FILELINE);
    for(int i=0;i<npts;i++)
    {
        FanDataPoint object;
        object.read(input);
        data.push_back(object);
    }

}

STRING AfeFanPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(lam) + ' ' + TO_STRING(turb) + ' ' + TO_STRING(expt) + ' ' + TO_STRING(rdens) + ' ' + TO_STRING(fdf) + ' ' + TO_STRING(sop) + ' ' + TO_STRING(off) + '\n';
    for(int i=0;i<4;i++)
        string += TO_STRING(fpc[i]) + ' ';
    string += '\n';
    string += TO_STRING(data.size()) + ' ' + TO_STRING(Sarea) + ' ' + TO_STRING(u_Sa) + '\n';
    for(unsigned int i=0;i<data.size();i++)
    {
        string += data[i].write();
    }
    return string;
}

void AfeFanPrivate::readDetails(Reader &input)
{
    lam = input.readNumber<RX>(FILELINE);
    turb = input.readNumber<RX>(FILELINE);
    expt = input.readNumber<RX>(FILELINE);
    rdens = input.readNumber<RX>(FILELINE);
    fdf = input.readNumber<RX>(FILELINE);
    sop = input.readNumber<RX>(FILELINE);
    off = input.readNumber<RX>(FILELINE);
    for(int i=0;i<4;i++)
        fpc.push_back(input.read<RX>(FILELINE));
    int npts = input.read<int>(FILELINE);
    Sarea = input.readNumber<RX>(FILELINE);
    u_Sa = input.read<int>(FILELINE);
    for(int i=0;i<npts;i++)
    {
        FanDataPoint object;
        object.read(input);
        data.push_back(object);
    }

}

AfeCsfPrivate::AfeCsfPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,int u_x,int u_y,std::vector<DataPoint> data):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),u_x(u_x),u_y(u_y),data(data)
{}

void AfeCsfPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    int npts = input.read<int>(FILELINE);
    u_x = input.read<int>(FILELINE);
    u_y = input.read<int>(FILELINE);
    for(int i=0;i<npts;i++)
    {
        DataPoint object;
        object.read(input);
        data.push_back(object);
    }

}

STRING AfeCsfPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(data.size()) + ' ' + TO_STRING(u_x) + ' ' + TO_STRING(u_y) + '\n';
    for(unsigned int i=0;i<data.size();i++)
    {
        string += data[i].write();
    }
    return string;
}

void AfeCsfPrivate::readDetails(Reader &input)
{
    int npts = input.read<int>(FILELINE);
    u_x = input.read<int>(FILELINE);
    u_y = input.read<int>(FILELINE);
    for(int i=0;i<npts;i++)
    {
        DataPoint object;
        object.read(input);
        data.push_back(object);
    }

}

AfeSupPrivate::AfeSupPrivate(int nr,int icon,STRING dataType,STRING name,STRING desc,int sched,int u_H,std::vector<AirflowSubelementData> subelements):nr(nr),icon(icon),dataType(dataType),name(name),desc(desc),sched(sched),u_H(u_H),subelements(subelements)
{}

void AfeSupPrivate::read(Reader &input)
{
    nr = input.read<int>(FILELINE);
    icon = input.read<int>(FILELINE);
    dataType = input.readString(FILELINE);
    name = input.readString(FILELINE);
    desc = input.readLine(FILELINE);
    int nse = input.read<int>(FILELINE);
    sched = input.read<int>(FILELINE);
    u_H = input.read<int>(FILELINE);
    for(int i=0;i<nse;i++)
    {
        AirflowSubelementData object;
        object.read(input);
        subelements.push_back(object);
    }

}

STRING AfeSupPrivate::write()
{
    STRING string;
    string += TO_STRING(nr) + ' ' + TO_STRING(icon) + ' ' + dataType + ' ' + name + '\n';
    string += desc + '\n';
    string += TO_STRING(subelements.size()) + ' ' + TO_STRING(sched) + ' ' + TO_STRING(u_H) + '\n';
    for(unsigned int i=0;i<subelements.size();i++)
    {
        string += subelements[i].write();
    }
    return string;
}

void AfeSupPrivate::readDetails(Reader &input)
{
    int nse = input.read<int>(FILELINE);
    sched = input.read<int>(FILELINE);
    u_H = input.read<int>(FILELINE);
    for(int i=0;i<nse;i++)
    {
        AirflowSubelementData object;
        object.read(input);
        subelements.push_back(object);
    }

}

} // prj
} // contam
} // openstudio
