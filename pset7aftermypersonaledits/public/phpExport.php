<?php
$mysqlDatabaseName ='finalproject';
$mysqlUserName ='therogerzou';
$mysqlPassword ='dingdingditch';
$mysqlHostName ='rzou-dreading-cs50-finalproject.cs50lyfe.info';
$mysqlExportPath = '~/cs50finance.sql';

//Export the database and output the status to the page
$command='mysqldump --opt -h' .$mysqlHostName .' -u' .$mysqlUserName .' -p' .$mysqlPassword .' ' .$mysqlDatabaseName .' > ~/' .$mysqlExportPath;
$output=array();
$worked;
exec($command,$output,$worked);
switch($worked){
case 0:
echo 'Database <b>' .$mysqlDatabaseName .'</b> successfully exported to <b>~/' .$mysqlExportPath .'</b>';
break;
case 1:
echo 'There was a warning during the export of <b>' .$mysqlDatabaseName .'</b> to <b>~/' .$mysqlExportPath .'</b>';
break;
case 2:
echo 'There was an error during export. Please check your values:<br/><br/><table><tr><td>MySQL Database Name:</td><td><b>' .$mysqlDatabaseName .'</b></td></tr><tr><td>MySQL User Name:</td><td><b>' .$mysqlUserName .'</b></td></tr><tr><td>MySQL Password:</td><td><b>NOTSHOWN</b></td></tr><tr><td>MySQL Host Name:</td><td><b>' .$mysqlHostName .'</b></td></tr></table>';
break;
}


/* <script type="text/javascript" src="https://www.dropbox.com/static/api/1/dropins.js" id="dropboxjs" data-app-key="7bp6sdyopdxcq8k"></script>
<a href="https://dl.dropboxusercontent.com/s/deroi5nwm6u7gdf/advice.png" class="dropbox-saver"></a>
*/


?>



<script type="text/javascript">
var client = new Dropbox.Client({key: 2sv3r79uto705f8});

// Try to finish OAuth authorization.
client.authenticate({interactive: false}, function (error) {
    if (error) {
        alert('Authentication error: ' + error);
    }
});

if (client.isAuthenticated()) {
    // Client is authenticated. Display UI.
    alert("authenticated :)");
    
}
</script>





