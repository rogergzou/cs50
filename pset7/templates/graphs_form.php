<div>
    <button id="view_total" type="submit">Total Spending Over Time</button>
</div>
<div>
    <button id="view_comparison" type="submit">Total Spending in Each Category</button>
</div>
<div>
    <script>
        var expenses_monthly = <?php echo json_encode($expenses_monthly); ?>;
        var sum = <?php echo json_encode($sum); ?>;
        var categories = <?php echo json_encode($categories_edited); ?>;
        var spending = <?php echo json_encode($spending); ?>;
    </script>
</div>
<div id="chart_total"></div>
<div id="chart_comparison"></div>
