#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QString>
#include <QStandardPaths>
#include <QSettings>
/*
	emit newStatus("Updating sovereignty data...");
	// alliance xml file: https://api.eveonline.com/eve/AllianceList.xml.aspx?version=1
	// QUrl eve_alliance_api("https://api.eveonline.com/eve/AllianceList.xml.aspx?version=1");
	QUrl eve_alliance_api("file:///D:/AllianceList.xml.xml");
	QUrl eve_sov_alliance_api("https://api.eveonline.com/map/Sovereignty.xml.aspx");
	QUrl eve_fw_api("https://api.eveonline.com/map/FacWarSystems.xml.aspx");
	*/

namespace EveJukebox {

class Properties
{
public:
	static QString Vendor() {
		return "Psikon";
	}

	static QString AppName() {
		return "Unofficial EVE Jukebox";
	}
	
	static QString EveApiAlliance() {
		return "file:///D:/AllianceList.xml.xml";
	}

	static QString EveApiSov() {
		return "https://api.eveonline.com/map/Sovereignty.xml.aspx";
	}

	static QString EveApiFacwar() {
		return "https://api.eveonline.com/map/FacWarSystems.xml.aspx";
	}

	static QString EveApiCharimg(QString charId) {
		return QString("http://image.eveonline.com/Character/%1_128.jpg").arg(charId);
	}

	static QString EveApiCharid() {
		return "https://api.eveonline.com/eve/CharacterID.xml.aspx";
	}

	static QString DataDir() {
		QString dataLocation = QStandardPaths::locate(QStandardPaths::DataLocation, QString(), QStandardPaths::LocateDirectory);
		return dataLocation + "/Psikon/Unofficial-EVE-Jukebox";
	}

	static QString PortraitsDir() {
		QString dataLocation = QStandardPaths::locate(QStandardPaths::DataLocation, QString(), QStandardPaths::LocateDirectory);
		return dataLocation + "/Psikon/Unofficial-EVE-Jukebox/portraits";
	}

	static QString CacheDir() {
		QString dataLocation = QStandardPaths::locate(QStandardPaths::DataLocation, QString(), QStandardPaths::LocateDirectory);
		return dataLocation + "/Psikon/Unofficial-EVE-Jukebox/cache";
	}

	static QString DbFile() {
		QString dataLocation = QStandardPaths::locate(QStandardPaths::DataLocation, QString(), QStandardPaths::LocateDirectory);
		return dataLocation + "/Psikon/Unofficial-EVE-Jukebox/uevejukebox.db";
	}

};

};
#endif // PROPERTIES_H