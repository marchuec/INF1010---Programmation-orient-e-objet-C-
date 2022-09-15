#ifndef GESTIONNAIREPATIENTS_H
#define GESTIONNAIREPATIENTS_H

#include <string>
#include "Patient.h"
#include <memory>
#include "vector"
#include "PatientEtudiant.h"


class GestionnairePatients
{
public:
    enum class TypePatient
    {
        first_ = -1,
        Patient,
        PatientEtudiant,
        last_
    };

    GestionnairePatients();

    Patient* chercherPatient(const std::string& numeroAssuranceMaladie);
    bool chargerDepuisFichier(const std::string& nomFichier);

    bool operator+=(Patient* patient);
    friend std::ostream& operator<<(std::ostream& os, const GestionnairePatients& gestionnairePatient);

    const std::vector<std::shared_ptr<Patient>>& getPatients() const;

    std::vector<PatientEtudiant*> getPatientsEtudiants() const;

    size_t getNbPatients() const;
    size_t getNbPatientsEtudiants() const;

    static constexpr size_t NB_PATIENT_MAX = 16;

private:
    bool lireLignePatient(const std::string& ligne);

    std::vector<std::shared_ptr<Patient>> patients_;
};

#endif // GESTIONNAIREPATIENTS_H