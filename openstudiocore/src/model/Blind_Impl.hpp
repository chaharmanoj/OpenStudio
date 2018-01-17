/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2018, Alliance for Sustainable Energy, LLC. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *
 *  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *  disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *  following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote
 *  products derived from this software without specific prior written permission from the respective party.
 *
 *  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative
 *  works may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without
 *  specific prior written permission from Alliance for Sustainable Energy, LLC.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER, THE UNITED STATES GOVERNMENT, OR ANY CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************************************************************/

#ifndef MODEL_BLIND_IMPL_HPP
#define MODEL_BLIND_IMPL_HPP

#include "ModelAPI.hpp"
#include "ShadingMaterial_Impl.hpp"

#include "../utilities/units/Quantity.hpp"
#include "../utilities/units/OSOptionalQuantity.hpp"

namespace openstudio {
namespace model {

namespace detail {

  /** Blind_Impl is a ShadingMaterial_Impl that is the implementation class for Blind.*/
  class MODEL_API Blind_Impl : public ShadingMaterial_Impl {


































































































































    // TODO: Add relationships for objects related to this one, but not pointed to by the underlying data.
    //       Such relationships can be generated by the GenerateRelationships.rb script.
   public:
    /** @name Constructors and Destructors */
    //@{

    Blind_Impl(const IdfObject& idfObject,
               Model_Impl* model,
               bool keepHandle);

    Blind_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
               Model_Impl* model,
               bool keepHandle);

    Blind_Impl(const Blind_Impl& other,
               Model_Impl* model,
               bool keepHandle);

    virtual ~Blind_Impl() {}

    //@}

    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const override;

    virtual IddObjectType iddObjectType() const override;

    //@}
    /** @name Getters */
    //@{

    /** Get the thickness of the material. For now is equivalent to slat thickness. */
    virtual double thickness() const override;

    std::string slatOrientation() const;
    /** Throws because blind has beam and diffuse visible transmittance. */
    virtual boost::optional<double> getVisibleTransmittance() const override;

    bool isSlatOrientationDefaulted() const;

    double slatWidth() const;

    Quantity getSlatWidth(bool returnIP=false) const;

    double slatSeparation() const;

    Quantity getSlatSeparation(bool returnIP=false) const;

    double slatThickness() const;

    Quantity getSlatThickness(bool returnIP=false) const;

    bool isSlatThicknessDefaulted() const;

    double slatAngle() const;

    Quantity getSlatAngle(bool returnIP=false) const;

    bool isSlatAngleDefaulted() const;

    double slatConductivity() const;

    Quantity getSlatConductivity(bool returnIP=false) const;

    bool isSlatConductivityDefaulted() const;

    double slatBeamSolarTransmittance() const;

    Quantity getSlatBeamSolarTransmittance(bool returnIP=false) const;

    bool isSlatBeamSolarTransmittanceDefaulted() const;

    double frontSideSlatBeamSolarReflectance() const;

    Quantity getFrontSideSlatBeamSolarReflectance(bool returnIP=false) const;

    double backSideSlatBeamSolarReflectance() const;

    Quantity getBackSideSlatBeamSolarReflectance(bool returnIP=false) const;

    double slatDiffuseSolarTransmittance() const;

    Quantity getSlatDiffuseSolarTransmittance(bool returnIP=false) const;

    bool isSlatDiffuseSolarTransmittanceDefaulted() const;

    double frontSideSlatDiffuseSolarReflectance() const;

    Quantity getFrontSideSlatDiffuseSolarReflectance(bool returnIP=false) const;

    double backSideSlatDiffuseSolarReflectance() const;

    Quantity getBackSideSlatDiffuseSolarReflectance(bool returnIP=false) const;

    double slatBeamVisibleTransmittance() const;

    Quantity getSlatBeamVisibleTransmittance(bool returnIP=false) const;

    boost::optional<double> frontSideSlatBeamVisibleReflectance() const;

    OSOptionalQuantity getFrontSideSlatBeamVisibleReflectance(bool returnIP=false) const;

    boost::optional<double> backSideSlatBeamVisibleReflectance() const;

    OSOptionalQuantity getBackSideSlatBeamVisibleReflectance(bool returnIP=false) const;

    double slatDiffuseVisibleTransmittance() const;

    Quantity getSlatDiffuseVisibleTransmittance(bool returnIP=false) const;

    bool isSlatDiffuseVisibleTransmittanceDefaulted() const;

    boost::optional<double> frontSideSlatDiffuseVisibleReflectance() const;

    OSOptionalQuantity getFrontSideSlatDiffuseVisibleReflectance(bool returnIP=false) const;

    boost::optional<double> backSideSlatDiffuseVisibleReflectance() const;

    OSOptionalQuantity getBackSideSlatDiffuseVisibleReflectance(bool returnIP=false) const;

    double slatInfraredHemisphericalTransmittance() const;

    Quantity getSlatInfraredHemisphericalTransmittance(bool returnIP=false) const;

    bool isSlatInfraredHemisphericalTransmittanceDefaulted() const;

    double frontSideSlatInfraredHemisphericalEmissivity() const;

    Quantity getFrontSideSlatInfraredHemisphericalEmissivity(bool returnIP=false) const;

    bool isFrontSideSlatInfraredHemisphericalEmissivityDefaulted() const;

    double backSideSlatInfraredHemisphericalEmissivity() const;

    Quantity getBackSideSlatInfraredHemisphericalEmissivity(bool returnIP=false) const;

    bool isBackSideSlatInfraredHemisphericalEmissivityDefaulted() const;

    double blindtoGlassDistance() const;

    Quantity getBlindtoGlassDistance(bool returnIP=false) const;

    bool isBlindtoGlassDistanceDefaulted() const;

    double blindTopOpeningMultiplier() const;

    Quantity getBlindTopOpeningMultiplier(bool returnIP=false) const;

    bool isBlindTopOpeningMultiplierDefaulted() const;

    double blindBottomOpeningMultiplier() const;

    Quantity getBlindBottomOpeningMultiplier(bool returnIP=false) const;

    bool isBlindBottomOpeningMultiplierDefaulted() const;

    double blindLeftSideOpeningMultiplier() const;

    Quantity getBlindLeftSideOpeningMultiplier(bool returnIP=false) const;

    bool isBlindLeftSideOpeningMultiplierDefaulted() const;

    double blindRightSideOpeningMultiplier() const;

    Quantity getBlindRightSideOpeningMultiplier(bool returnIP=false) const;

    bool isBlindRightSideOpeningMultiplierDefaulted() const;

    double minimumSlatAngle() const;

    Quantity getMinimumSlatAngle(bool returnIP=false) const;

    bool isMinimumSlatAngleDefaulted() const;

    double maximumSlatAngle() const;

    Quantity getMaximumSlatAngle(bool returnIP=false) const;

    bool isMaximumSlatAngleDefaulted() const;

    //@}
    /** @name Setters */
    //@{

    /** Set thickness to value (m). For now is equivalent to setting slat thickness. */
    virtual bool setThickness(double value) override;

    bool setSlatOrientation(std::string slatOrientation);

    void resetSlatOrientation();

    bool setSlatWidth(double slatWidth);

    bool setSlatWidth(const Quantity& slatWidth);

    bool setSlatSeparation(double slatSeparation);

    bool setSlatSeparation(const Quantity& slatSeparation);

    bool setSlatThickness(double slatThickness);

    bool setSlatThickness(const Quantity& slatThickness);

    void resetSlatThickness();

    bool setSlatAngle(double slatAngle);

    bool setSlatAngle(const Quantity& slatAngle);

    void resetSlatAngle();

    bool setSlatConductivity(double slatConductivity);

    bool setSlatConductivity(const Quantity& slatConductivity);

    void resetSlatConductivity();

    bool setSlatBeamSolarTransmittance(double slatBeamSolarTransmittance);

    bool setSlatBeamSolarTransmittance(const Quantity& slatBeamSolarTransmittance);

    void resetSlatBeamSolarTransmittance();

    bool setFrontSideSlatBeamSolarReflectance(double frontSideSlatBeamSolarReflectance);

    bool setFrontSideSlatBeamSolarReflectance(const Quantity& frontSideSlatBeamSolarReflectance);

    bool setBackSideSlatBeamSolarReflectance(double backSideSlatBeamSolarReflectance);

    bool setBackSideSlatBeamSolarReflectance(const Quantity& backSideSlatBeamSolarReflectance);

    bool setSlatDiffuseSolarTransmittance(double slatDiffuseSolarTransmittance);

    bool setSlatDiffuseSolarTransmittance(const Quantity& slatDiffuseSolarTransmittance);

    void resetSlatDiffuseSolarTransmittance();

    bool setFrontSideSlatDiffuseSolarReflectance(double frontSideSlatDiffuseSolarReflectance);

    bool setFrontSideSlatDiffuseSolarReflectance(const Quantity& frontSideSlatDiffuseSolarReflectance);

    bool setBackSideSlatDiffuseSolarReflectance(double backSideSlatDiffuseSolarReflectance);

    bool setBackSideSlatDiffuseSolarReflectance(const Quantity& backSideSlatDiffuseSolarReflectance);

    bool setSlatBeamVisibleTransmittance(double slatBeamVisibleTransmittance);

    bool setSlatBeamVisibleTransmittance(const Quantity& slatBeamVisibleTransmittance);

    bool setFrontSideSlatBeamVisibleReflectance(boost::optional<double> frontSideSlatBeamVisibleReflectance);

    bool setFrontSideSlatBeamVisibleReflectance(const OSOptionalQuantity& frontSideSlatBeamVisibleReflectance);

    void resetFrontSideSlatBeamVisibleReflectance();

    bool setBackSideSlatBeamVisibleReflectance(boost::optional<double> backSideSlatBeamVisibleReflectance);

    bool setBackSideSlatBeamVisibleReflectance(const OSOptionalQuantity& backSideSlatBeamVisibleReflectance);

    void resetBackSideSlatBeamVisibleReflectance();

    bool setSlatDiffuseVisibleTransmittance(double slatDiffuseVisibleTransmittance);

    bool setSlatDiffuseVisibleTransmittance(const Quantity& slatDiffuseVisibleTransmittance);

    void resetSlatDiffuseVisibleTransmittance();

    bool setFrontSideSlatDiffuseVisibleReflectance(boost::optional<double> frontSideSlatDiffuseVisibleReflectance);

    bool setFrontSideSlatDiffuseVisibleReflectance(const OSOptionalQuantity& frontSideSlatDiffuseVisibleReflectance);

    void resetFrontSideSlatDiffuseVisibleReflectance();

    bool setBackSideSlatDiffuseVisibleReflectance(boost::optional<double> backSideSlatDiffuseVisibleReflectance);

    bool setBackSideSlatDiffuseVisibleReflectance(const OSOptionalQuantity& backSideSlatDiffuseVisibleReflectance);

    void resetBackSideSlatDiffuseVisibleReflectance();

    bool setSlatInfraredHemisphericalTransmittance(double slatInfraredHemisphericalTransmittance);

    bool setSlatInfraredHemisphericalTransmittance(const Quantity& slatInfraredHemisphericalTransmittance);

    void resetSlatInfraredHemisphericalTransmittance();

    bool setFrontSideSlatInfraredHemisphericalEmissivity(double frontSideSlatInfraredHemisphericalEmissivity);

    bool setFrontSideSlatInfraredHemisphericalEmissivity(const Quantity& frontSideSlatInfraredHemisphericalEmissivity);

    void resetFrontSideSlatInfraredHemisphericalEmissivity();

    bool setBackSideSlatInfraredHemisphericalEmissivity(double backSideSlatInfraredHemisphericalEmissivity);

    bool setBackSideSlatInfraredHemisphericalEmissivity(const Quantity& backSideSlatInfraredHemisphericalEmissivity);

    void resetBackSideSlatInfraredHemisphericalEmissivity();

    bool setBlindtoGlassDistance(double blindtoGlassDistance);

    bool setBlindtoGlassDistance(const Quantity& blindtoGlassDistance);

    void resetBlindtoGlassDistance();

    bool setBlindTopOpeningMultiplier(double blindTopOpeningMultiplier);

    bool setBlindTopOpeningMultiplier(const Quantity& blindTopOpeningMultiplier);

    void resetBlindTopOpeningMultiplier();

    bool setBlindBottomOpeningMultiplier(double blindBottomOpeningMultiplier);

    bool setBlindBottomOpeningMultiplier(const Quantity& blindBottomOpeningMultiplier);

    void resetBlindBottomOpeningMultiplier();

    bool setBlindLeftSideOpeningMultiplier(double blindLeftSideOpeningMultiplier);

    bool setBlindLeftSideOpeningMultiplier(const Quantity& blindLeftSideOpeningMultiplier);

    void resetBlindLeftSideOpeningMultiplier();

    bool setBlindRightSideOpeningMultiplier(double blindRightSideOpeningMultiplier);

    bool setBlindRightSideOpeningMultiplier(const Quantity& blindRightSideOpeningMultiplier);

    void resetBlindRightSideOpeningMultiplier();

    bool setMinimumSlatAngle(double minimumSlatAngle);

    bool setMinimumSlatAngle(const Quantity& minimumSlatAngle);

    void resetMinimumSlatAngle();

    bool setMaximumSlatAngle(double maximumSlatAngle);

    bool setMaximumSlatAngle(const Quantity& maximumSlatAngle);

    void resetMaximumSlatAngle();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.Blind");

    std::vector<std::string> slatOrientationValues() const;
    openstudio::Quantity slatWidth_SI() const;
    openstudio::Quantity slatWidth_IP() const;
    openstudio::Quantity slatSeparation_SI() const;
    openstudio::Quantity slatSeparation_IP() const;
    openstudio::Quantity slatThickness_SI() const;
    openstudio::Quantity slatThickness_IP() const;
    openstudio::Quantity slatAngle_SI() const;
    openstudio::Quantity slatAngle_IP() const;
    openstudio::Quantity slatConductivity_SI() const;
    openstudio::Quantity slatConductivity_IP() const;
    openstudio::Quantity slatBeamSolarTransmittance_SI() const;
    openstudio::Quantity slatBeamSolarTransmittance_IP() const;
    openstudio::Quantity frontSideSlatBeamSolarReflectance_SI() const;
    openstudio::Quantity frontSideSlatBeamSolarReflectance_IP() const;
    openstudio::Quantity backSideSlatBeamSolarReflectance_SI() const;
    openstudio::Quantity backSideSlatBeamSolarReflectance_IP() const;
    openstudio::Quantity slatDiffuseSolarTransmittance_SI() const;
    openstudio::Quantity slatDiffuseSolarTransmittance_IP() const;
    openstudio::Quantity frontSideSlatDiffuseSolarReflectance_SI() const;
    openstudio::Quantity frontSideSlatDiffuseSolarReflectance_IP() const;
    openstudio::Quantity backSideSlatDiffuseSolarReflectance_SI() const;
    openstudio::Quantity backSideSlatDiffuseSolarReflectance_IP() const;
    openstudio::Quantity slatBeamVisibleTransmittance_SI() const;
    openstudio::Quantity slatBeamVisibleTransmittance_IP() const;
    openstudio::OSOptionalQuantity frontSideSlatBeamVisibleReflectance_SI() const;
    openstudio::OSOptionalQuantity frontSideSlatBeamVisibleReflectance_IP() const;
    openstudio::OSOptionalQuantity backSideSlatBeamVisibleReflectance_SI() const;
    openstudio::OSOptionalQuantity backSideSlatBeamVisibleReflectance_IP() const;
    openstudio::Quantity slatDiffuseVisibleTransmittance_SI() const;
    openstudio::Quantity slatDiffuseVisibleTransmittance_IP() const;
    openstudio::OSOptionalQuantity frontSideSlatDiffuseVisibleReflectance_SI() const;
    openstudio::OSOptionalQuantity frontSideSlatDiffuseVisibleReflectance_IP() const;
    openstudio::OSOptionalQuantity backSideSlatDiffuseVisibleReflectance_SI() const;
    openstudio::OSOptionalQuantity backSideSlatDiffuseVisibleReflectance_IP() const;
    openstudio::Quantity slatInfraredHemisphericalTransmittance_SI() const;
    openstudio::Quantity slatInfraredHemisphericalTransmittance_IP() const;
    openstudio::Quantity frontSideSlatInfraredHemisphericalEmissivity_SI() const;
    openstudio::Quantity frontSideSlatInfraredHemisphericalEmissivity_IP() const;
    openstudio::Quantity backSideSlatInfraredHemisphericalEmissivity_SI() const;
    openstudio::Quantity backSideSlatInfraredHemisphericalEmissivity_IP() const;
    openstudio::Quantity blindtoGlassDistance_SI() const;
    openstudio::Quantity blindtoGlassDistance_IP() const;
    openstudio::Quantity blindTopOpeningMultiplier_SI() const;
    openstudio::Quantity blindTopOpeningMultiplier_IP() const;
    openstudio::Quantity blindBottomOpeningMultiplier_SI() const;
    openstudio::Quantity blindBottomOpeningMultiplier_IP() const;
    openstudio::Quantity blindLeftSideOpeningMultiplier_SI() const;
    openstudio::Quantity blindLeftSideOpeningMultiplier_IP() const;
    openstudio::Quantity blindRightSideOpeningMultiplier_SI() const;
    openstudio::Quantity blindRightSideOpeningMultiplier_IP() const;
    openstudio::Quantity minimumSlatAngle_SI() const;
    openstudio::Quantity minimumSlatAngle_IP() const;
    openstudio::Quantity maximumSlatAngle_SI() const;
    openstudio::Quantity maximumSlatAngle_IP() const;
  };

} // detail

} // model
} // openstudio

#endif // MODEL_BLIND_IMPL_HPP

