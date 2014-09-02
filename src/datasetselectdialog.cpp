/***************************************************************************
 SocNetV: Social Networks Visualizer
 version: 1.5
 Written in Qt
 
                         datasetselectdialog.cpp  -  description
                             -------------------
    copyright            : (C) 2005-2014 by Dimitris B. Kalamaras
    email                : dimitris.kalamaras@gmail.com
 ***************************************************************************/

/*******************************************************************************
*     This program is free software: you can redistribute it and/or modify     *
*     it under the terms of the GNU General Public License as published by     *
*     the Free Software Foundation, either version 3 of the License, or        *
*     (at your option) any later version.                                      *
*                                                                              *
*     This program is distributed in the hope that it will be useful,          *
*     but WITHOUT ANY WARRANTY; without even the implied warranty of           *
*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
*     GNU General Public License for more details.                             *
*                                                                              *
*     You should have received a copy of the GNU General Public License        *
*     along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
********************************************************************************/

 

#include "datasetselectdialog.h"

#include <QDebug>
#include <QPushButton>


DataSetSelectDialog::DataSetSelectDialog (QWidget *parent) : QDialog (parent)
{
    ui.setupUi(this);

    (ui.buttonBox) -> button (QDialogButtonBox::Ok) -> setDefault(true);

    datasets_list
            << "Krackhardt: High-tech managers (advice), 24 actors"
            << "Krackhardt: High-tech managers (friendship), 24 actors"
            << "Krackhardt: High-tech managers (Reports To), 24 actors"
            << "Padgett: Florentine Families (marital relationship), 16 actors"
            << "Padgett: Florentine Families (business relationship), 16 actors"
            << "Zachary: Karate Club (simple ties), 34 actors"
            << "Zachary: Karate Club (weighted ties), 34 actors"
            << "Bernard: Killworth Fraternity (multirelational), 58 actors"
            << "Galaskiewicz: CEOs and clubs (affiliation data)"
            << "Freeman's EIES networks (multirelational, 32 actors)"
            << "Freeman: EIES network, at time-1, 48 actors"
            << "Freeman: EIES network, at time-2, 48 actors"
            << "Freeman: EIES network, number of messages, 48 actors"
            << "Mexican Power Network in the 1940s (list format)"
            << "Knocke: Bureacracies Information Exchange Network, 10 actors"
            << "Wasserman & Faust: Countries Trade (basic manufactured goods), 24 actors";

    datasets_filenames
            << "Krackhardt_High-tech_managers_Advice_relation.sm"
            << "Krackhardt_High-tech_managers_Friendship_relation.sm"
            << "Krackhardt_High-tech_managers_ReportsTo_relation.sm"
            << "Padgett_Florentine_Families_Marital_relation.net"
            << "Padgett_Florentine_Families_Business_relation.paj"
            << "Zachary_Karate_Club_Simple_Ties.sm"
            << "Zachary_Karate_Club_Weighted_Ties.sm"
            << "Bernard_Killworth_Fraternity.dl"
            << "Galaskiewicz_CEOs_and_clubs_affiliation_network_data.2sm"
            << "Freeman_EIES_networks_32actors.dl"
            << "Freeman_EIES_network_48actors_Acquaintanceship_at_time-1.dl"
            << "Freeman_EIES_network_48actors_Acquaintanceship_at_time-2.dl"
            << "Freeman_EIES_network_48actors_Messages.dl"
            << "Mexican_Power_Network_1940s.lst"
            << "Knocke_Bureacracies_Information_Exchange_Network.pajek"
            << "Wasserman_Faust_Countries_Trade_Data_Basic_Manufactured_Goods.pajek";

    (ui.selectBox) -> insertItems( 1, datasets_list );
}



void DataSetSelectDialog::gatherData(){
    qDebug()<< "DataSetSelectDialog: gathering Data!...";
    int index = (ui.selectBox) -> currentIndex();
    QString dataset_name = datasets_filenames[index];
    qDebug()<< "DataSetSelectDialog: user selected: " << dataset_name;
	emit userChoices( dataset_name );
			
}


void DataSetSelectDialog::on_buttonBox_accepted()
{
    this->gatherData();
    this->accept();
}

void DataSetSelectDialog::on_buttonBox_rejected()
{
    this->reject();
}

DataSetSelectDialog::~DataSetSelectDialog(){
     datasets_list.clear(); datasets_filenames.clear();
}