<?php

    // configuration
    require("../includes/config.php");
    // SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    //UPDATE users SET cash = cash - ? WHERE id =?", $cash, $_SESSION["id"]
    if (query("UPDATE users SET cash = cash + 5000 WHERE id = ?", $_SESSION["id"])===false)
    {
        apologize("Was unable to add your cash");
    }
    redirect("index.php");
    
?>
