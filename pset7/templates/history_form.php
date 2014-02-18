<table>
    <thead>
        <th>Type</th>
        <th>Amount</th>
        <th>Time</th>
    </head>
    
    <tbody>
    <?php
    
    foreach ($history as $entry)
    {
        echo "<tr>";
        echo "<td>" . $entry["type"] . "</td>";
        echo "<td>" . $entry["amount"] . "</td>";
        echo "<td>" . $entry["time"] . "</td>";
        echo "</tr>";
    }
    
    ?>
    </tbody>
</table>
