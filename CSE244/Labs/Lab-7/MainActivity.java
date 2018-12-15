package com.example.jem2.lab07;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    public void updateSchedule() {
        Spinner teams = findViewById(R.id.teamSpinner);
        int n = Integer.valueOf(teams.getSelectedItem().toString());
        int match[][] = new int[n][n];
        String outputText = new String();
        TextView scheduleText = findViewById(R.id.scheduleView);
        for (int home_team = 1; home_team < n; home_team++) {
            for (int away_team = home_team+1 ; away_team <= n; away_team++) {
                int day = (home_team-3+away_team)%n;
                match[home_team][day] = away_team;
            }
        }

        outputText = outputText.concat(getString(R.string.schedule_title, n, n));
        for (int day=0; day < n; day++) {
            outputText = outputText.concat(getString(R.string.day_title, day+1));
            for (int home_team=1; home_team < n; home_team++) {
                if (match[home_team][day] != 0) {
                    outputText = outputText.concat(getString(R.string.match_string, home_team, match[home_team][day]));
                }
            }
        }
        scheduleText.setText(outputText);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Spinner teams = findViewById(R.id.teamSpinner);
        List<String> teamsList = new ArrayList<String>();
        for (int i = 3; i <= 20; i++) {
            teamsList.add(String.format("%d", i));
        }
        ArrayAdapter<String> teamsAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item, teamsList);
        teams.setAdapter(teamsAdapter);
        TextView scheduleText = findViewById(R.id.scheduleView);
        scheduleText.setMovementMethod(new ScrollingMovementMethod());
        teams.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                updateSchedule();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

    }
}
