#include "AnticheatMgr.h"
#include "Chat.h"
#include "Language.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"

void main () {
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        trans->Append("TRUNCATE TABLE players_reports_status");
        trans->Append("INSERT INTO `players_reports_status` (`guid`, `creation_time`, `average`, `total_reports`, `speed_reports`, `fly_reports`, `jump_reports`, `waterwalk_reports`) VALUES ('1', '235626', '3', '6', '23', '7', '2', '1')");
        trans->Append("INSERT INTO `players_reports_status` (`guid`, `creation_time`, `average`, `total_reports`, `speed_reports`, `fly_reports`, `jump_reports`) VALUES ('2', '329058', '1', '5', '12', '6', '7')");
	CharacterDatabase.DirectCommitTransaction(trans);

	if (CharacterDatabase.ErrorStatus != 0) {
		TC_LOG_INFO("assertion.error", "Failed to insert data!");
	}
	else {
		TC_LOG_INFO("assertion.success", "Test succesfully passed!");
	}
}