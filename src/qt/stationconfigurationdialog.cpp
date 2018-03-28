#include "stationconfigurationdialog.h"
#include "ui_stationconfigurationdialog.h"
#include "stationsettings.h"
#include <QtDebug>
#include <QMessageBox>
#include <QIcon>
#include "symbols.h"

StationConfigurationDialog::StationConfigurationDialog(StationSettings *settings, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::StationConfigurationDialog),
    mySettings(settings)
{
    ui->setupUi(this);
    connect(ui->disablePHGCheckbox,SIGNAL(stateChanged(int)),this,SLOT(disablePHBChanged(int)));
    connect(ui->groupEdit, SIGNAL(textChanged(QString)), this, SLOT(symbolSettingsChanged(QString)));
    connect(ui->symbolEdit, SIGNAL(textChanged(QString)), this, SLOT(symbolSettingsChanged(QString)));


    ui->callsignEdit->setText(settings->callsign());
    ui->compressedPacketsCheckbox->setChecked(settings->sendCompressed());

    ui->latDegEdit->setText(settings->lat().left(2));
    ui->latMinEdit->setText(settings->lat().mid(2,settings->lat().length()-3));
    ui->latDirEdit->setText(settings->lat().right(1));

    ui->lonDegEdit->setText(settings->lon().left(2));
    ui->lonMinEdit->setText(settings->lon().mid(2,settings->lon().length()-3));
    ui->lonDirEdit->setText(settings->lon().right(1));

    disablePHBChanged(!settings->hasPHGD());
    ui->disablePHGCheckbox->setChecked(!settings->hasPHGD());
    ui->commentLineEdit->setText(settings->comment());
    ui->groupEdit->setText(QString(settings->group()));
    ui->symbolEdit->setText(QString(settings->symbol()));

    char key[4];
    key[0] = '/';
    key[1] = 'y';
    key[2] = ' ';
    key[3] = 0;
    Symbol *sym = symbol_data[key];
    QPixmap pix = sym->pix;
    ui->symbolSelectButton->setIcon(QIcon(pix));
}

StationConfigurationDialog::~StationConfigurationDialog()
{
    delete ui;
}

void StationConfigurationDialog::disablePHBChanged(int state)
{
    ui->powerCombo->setEnabled(!state);
    ui->gainCombo->setEnabled(!state);
    ui->heightCombo->setEnabled(!state);
    ui->directivityCombo->setEnabled(!state);
}

void StationConfigurationDialog::symbolSettingsChanged(QString t)
{
    Q_UNUSED(t)
    char key[4];
    key[0] = ui->groupEdit->text()[0].cell();
    key[1] = ui->symbolEdit->text()[0].cell();
    key[2] = ' ';
    key[3] = 0;

    if(symbol_data.contains(key)) {
        ui->icon->setPixmap(symbol_data[key]->pix);
    } else {
        ui->icon->clear();
    }
}

void StationConfigurationDialog::accept()
{
    QString st_DirNS = "N";
    QString st_DirEW = "E";
    int ok = 1;

    if (ui->latDirEdit->text() == "N"){
         st_DirNS = "N";
    } else {
         st_DirNS = "S";
    }

    float st_lat_deg = ui->latDegEdit->text().toInt();

    if ((st_lat_deg > 90) || (st_lat_deg < 0)) {
        ok = 0;
    }

    float st_lat_min = ui->latMinEdit->text().toFloat();

    if ((st_lat_min >= 60.0) || (st_lat_deg < 0.0)) {
         ok = 0;
    }

    if ((st_lat_deg == 90) && (st_lat_min != 0.0)) {
         ok = 0;
    }

    QString station_lat = ui->latDegEdit->text() + ui->latMinEdit->text() + ui->latDirEdit->text();

    if (ui->lonDirEdit->text() == "E"){
         st_DirEW = "E";
    } else {
         st_DirEW = "W";
    }

    float st_lon_deg = ui->lonDegEdit->text().toInt();

    if ((st_lon_deg > 180) || (st_lon_deg < 0)) {
        ok = 0;
    }

    float st_lon_min = ui->lonMinEdit->text().toFloat();

    if ((st_lon_min >= 60.0) || (st_lon_deg < 0.0)) {
         ok = 0;
    }

    if ((st_lon_deg == 180) && (st_lat_min != 0.0)) {
         ok = 0;
    }

    QString station_lon = ui->lonDegEdit->text() + ui->lonMinEdit->text() + ui->lonDirEdit->text();

    if (!ok) {
        QMessageBox::question(this,"Configuration Settings","Errors in Configuration. \n Are you sure?",QMessageBox::Yes | QMessageBox::No);
    }


    if (ok) {
        mySettings->setCallsign(ui->callsignEdit->text());
        mySettings->setSendCompressed(ui->compressedPacketsCheckbox->isChecked());
        mySettings->setLat(station_lat);
        mySettings->setLon(station_lon);
        mySettings->setGroup(ui->groupEdit->text()[0].cell());
        mySettings->setSymbol(ui->symbolEdit->text()[0].cell());
        mySettings->setComment(ui->commentLineEdit->text());
        mySettings->sethasPHGD(!ui->disablePHGCheckbox->isChecked());
    }
    QDialog::accept();
}

