<?php
    
    // configuration
    require("../includes/config.php");
    
    $history = query("SELECT type, amount, time FROM total WHERE id = ?", $_SESSION["id"]);
    
    render("history_form.php", ["title" => "History", "history" => $history]);
?>
