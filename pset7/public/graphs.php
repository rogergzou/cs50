<?php

    // sharp define 7

    // configuration
    require("../includes/config.php");

    // graph for total spending
    
    $expenses = query("SELECT amount, time FROM total WHERE id = ?", $_SESSION["id"]);
    
    for ($i = 0, $n = count($expenses); $i < $n; $i++)
    {
        $expenses[$i]["time"] = substr($expenses[$i]["time"], 0, 7);
    }
    
    $expenses_monthly = [];
    
    $expenses_index = 0;
    
    for ($i = 0, $n = count($expenses); $i < $n; $i++)
    {
        if ($i != 0 && $expenses[$i]["time"] == $expenses[$i - 1]["time"])
        {
            continue;
        }
        
        $expenses_monthly[$expenses_index] = $expenses[$i]["time"];
        $expenses_index++;
    }
    
    $sum = [];
    
    $sum_index = 0;
    
    $total_sum = 0;
    
    for ($i = 0, $n = count($expenses); $i < $n; $i++)
    {
        if ($i == 0 || $expenses[$i]["time"] == $expenses[$i - 1]["time"])
        {
            $total_sum = $total_sum + $expenses[$i]["amount"];
        }
        else
        {
            $sum[$sum_index] = $total_sum;
            $total_sum = $expenses[$i]["amount"];
            $sum_index++;
        }
    }
    
    $sum[$sum_index] = $total_sum;
    
    // graph for comparison between expenses and limits
    
    $categories = query("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'expenses'");
    $categories_edited = [];
    for ($i = 2, $n = count($categories); $i < $n; $i++)
    {
        $categories_edited[$i - 2] = $categories[$i];
    }
    
    for ($i = 0, $n = count($categories_edited); $i < $n; $i++)
    {
        $categories_edited[$i] = $categories_edited[$i]["COLUMN_NAME"];
    }
    
    $spending = [];
    
    for ($i = 0, $n < count($categories_edited); $i < $n; $i++)
    {
        $sql_temp = query("SELECT $categories_edited[$i] FROM expenses WHERE id = ?", $_SESSION["id"]);
        $spending[$i] = $sql_temp[0][$categories_edited[$i]];
    }
    
    render("graphs_form.php", ["title" => "graphs", "expenses_monthly" => $expenses_monthly, "sum" => $sum, "categories_edited" => $categories_edited, "spending" => $spending]);
    
?>
